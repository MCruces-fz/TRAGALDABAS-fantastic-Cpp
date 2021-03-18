
// -------------------------------------------------- //
//       -------   H O W   T O   U S E   -------      //
//                                                    //
//           $ root                                   //
//           root [0] .L event_topology.C             //
//           root [1] main()                          //
//                                                    //
// -------------------------------------------------- //


#include "MIDAS.C"
#include "bad_cells.h"
#include "../utils/constants.h"
#include "../utils/footilities.h"

// using namespace std;


// File constants and structs
Event** event;          // Event class 
TRpcHit** rpc_hit;      // Hit class
TRpcSaeta** rpc_saeta;  // Saeta class

list<int>::iterator it;
Int_t weighted_mult;


void event_topology() {
    string root_full_path = "/home/mcruces/Documents/fptrucha_hits/root/tr20263112419.hld.root.root"; 

    // ROOT Full Input Path as Char array
    int path_len = root_full_path.length();
    char root_char_path[path_len + 1];
    strcpy(root_char_path, root_full_path.c_str());

    // ROOT Filename ID
    char *file0 = basename(root_char_path);
    string root_full_name = file0;
    string filename_id = root_full_name.substr(2,11);
    
    // Date ID
    string yydoy = filename_id.substr(0, 5);
    
    // Bad cells Filename
    string bc_filename = "bad_cells_" + yydoy + ".csv";
    
    //--  Read TTree  -----------------------------------------------
    TFile* t_file = new TFile(root_char_path, "READ");
    TTree* tree  = (TTree*) t_file -> Get("T");

    //--  Read Bad Cells  -------------------------------------------

    string bc_fulll_path = c_bc_dir + bc_filename;
    ReturnBC bad_cells = read_bad_cells(bc_fulll_path);
    if (silly_prints) cout << "Bad cells of 20270: " << bad_cells.T1[0] << endl;

    // Loop variables:
    Int_t nhits, nsaetas;

    //--  Reading TClonesArrays -------------------------------------

    // Steps:
    //   1.- Declared TClonesArray
    //   2.- Defined TClonesArray of TRpcHit objects
    //   3.- Defined rpchit branch as pointer
    //   4.- Set TRpcHit objects of rpchit branch for hits_carray TClonesArray
    //   5.- Declared instance of TRpcHit class (I'll use it later)

    //----  Hits
    TClonesArray* hits_carray;                                        // 1.
    hits_carray = new TClonesArray("TRpcHit");                        // 2.
    TBranch *branch_rpchit = tree -> GetBranch("rpchit");             // 3.
    branch_rpchit -> SetAddress(&hits_carray);                        // 4.
    TRpcHit** rpc_hit;                                                // 5.

    //----  Saetas
    TClonesArray* saetas_carray;                                      // 1.
    saetas_carray = new TClonesArray("TRpcSaeta");                    // 2.
    TBranch *branch_rpcsaeta = tree -> GetBranch("RpcSaeta3Planes");  // 3.
    branch_rpcsaeta -> SetAddress(&saetas_carray);                    // 4.
    TRpcSaeta** rpc_saeta;                                            // 5.

    //---------------------------------------------------------------

    Long64_t nevents = tree->GetEntries();
    if (silly_prints) cout << "Number of events: " << nevents << c_constant << endl;

    Int_t nmuons = 0;
    Int_t nevt_passed = 0;
    for (int ievt = 0; ievt < nevents; ievt++) {

        tree -> GetEvent(ievt);
        nhits = hits_carray -> GetEntries();
        nsaetas = saetas_carray -> GetEntries();
        
        if (nsaetas == 0) continue;

        HitsPerPlane hitspp;
        hitspp = hits_topology(hits_carray, rpc_hit, bad_cells);
        weighted_mult = 2 * hitspp.T3 + 3 * hitspp.T4;  // Weighted multiplicity

        SaetasData saetad;
        saetad = saetas_counter(saetas_carray, rpc_saeta, hitspp.ind_k);

        if (saetad.chi_2 >= 100) continue;

        // Get MIDAS values
        ReturnMIDAS midas = particle_midas(saetad.chi_2, weighted_mult, nhits);

        if (silly_prints) {
            cout << "Hits per plane: " << hitspp.T1 << ", " << hitspp.T3 << ", " << hitspp.T4 << endl;
            cout << "mylist contains:";
            for (it=hitspp.ind_k.begin(); it!=hitspp.ind_k.end(); ++it) cout << ' ' << *it;
            cout << '\n';
            cout << saetad.number << " Saetas, with best Chi2: " << saetad.chi_2 << endl;
            cout << "ID: " << midas.id << ", Hello " << c_z0_plane[0] << endl;
            if (midas.id == 13) cout << "-------------------------------------------------------" << endl;
            cout << "Parameters of ParticleMIDAS: " << saetad.chi_2 << ", " << weighted_mult << ", " << nhits << endl;
            cout << "Particle ID: " << midas.id << ", P(ID) = " << midas.p_id << ", Chi2(ID) = " << saetad.chi_2 << endl;
            if (midas.id == 13) cout << "-------------------------------------------------------" << endl;
            cout << "\n\n" << endl;
        }

        if (out_prints) {
            cout << filename_id << "," << ievt << ","  << midas.id << "," << midas.p_id << "," << saetad.chi_2 << "," << hitspp.T1 << "," << hitspp.T3 << "," << hitspp.T4 << endl;
        }

        if (midas.id == 13) nmuons++;
        nevt_passed++;
    }

    // Stats at END:
    cout << "Number of events passed: " << nevt_passed << ", muons: " << nmuons << endl;
}


// int main() {
//     string filename = "/home/mcruces/Documents/fptrucha_hits/root/tr20263112419.hld.root.root";
//     event_topology(filename);
//     return 0;
// }
