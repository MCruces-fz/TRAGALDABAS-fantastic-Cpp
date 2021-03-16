
#include "MIDAS.C"
#include "bad_cells.h"
#include "../utils/constants.h"
#include "../utils/footilities.h"

// using namespace std;


// File constants and structs

Event** event;  // Event class 
TRpcHit** rpc_hit;  // Hit class
TRpcSaeta** rpc_saeta;  // Saeta class


void event_topology() {

    // Date Constants:
    string yy = "20";
    string doy = "270";
    string yydoy = yy + doy;

    // Filenames:
    // --> Bad cells
    string bc_filename = "bad_cells_" + yydoy + ".csv";
    // --> Root file
    string root_filename = "tr20259084207.hld.root.root";

    // Loop variables:
    Int_t nhits, nsaetas;

    // Full Paths:
    // --> Bad cells
    string bc_fulll_path = c_bc_dir + bc_filename;
    // --> Root file
    string root_full_path = c_root_dir + root_filename;


    //--  Read Bad Cells  ------------------------------------------

    ReturnBC bad_cells = read_bad_cells(bc_fulll_path);
    cout << "Bad cells of 20270: " << bad_cells.T1[0] << endl;

    //--  Read TFile  ----------------------------------------------

    // (It needs a char as input)
    int path_len = root_full_path.length();
    char root_char_path[path_len + 1];
    strcpy(root_char_path, root_full_path.c_str());

    TFile* t_file = new TFile(root_char_path, "READ");

    // Read TTree:
    TTree* tree  = (TTree*) t_file -> Get("T");

    //--  Reading TClonesArrays -------------------------------------

    // Steps:
    //   1.- Declared TClonesArray
    //   2.- Defined TClonesArray of TRpcHit objects
    //   3.- Defined rpchit branch as pointer
    //   4.- Set TRpcHit objects of rpchit branch for hits_carray TClonesArray
    //   5.- Declared instance of TRpcHit class (I'll use it later)

    //----  Hits
    TClonesArray* hits_carray;                                       // 1.
    hits_carray = new TClonesArray("TRpcHit");                       // 2.
    TBranch *branch_rpchit = tree -> GetBranch("rpchit");            // 3.
    branch_rpchit -> SetAddress(&hits_carray);                       // 4.
    TRpcHit** rpc_hit;                                               // 5.

    //----  Saetas
    TClonesArray* saetas_carray;                                      // 1.
    saetas_carray = new TClonesArray("TRpcSaeta");                    // 2.
    TBranch *branch_rpcsaeta = tree -> GetBranch("RpcSaeta3Planes");  // 3.
    branch_rpcsaeta -> SetAddress(&saetas_carray);                    // 4.
    TRpcSaeta** rpc_saeta;                                            // 5.

    //----------------------------------------------------------------

    Long64_t nevents = tree->GetEntries();
    cout << "Number of events: " << nevents << c_constant << endl;

    for (int ievt = 0; ievt < nevents; ievt++) {

        tree -> GetEvent(ievt);
        nhits = hits_carray -> GetEntries();
        nsaetas = saetas_carray -> GetEntries();
        
        if (nsaetas == 0) continue;
        cout << "In event " << ievt << "; " << nsaetas << " saetas, " << nhits << " hits." << endl;

        HitsPerPlane hitspp;
        hitspp = hits_topology(hits_carray, rpc_hit);
        cout << "Hits per plane: " << hitspp.T1 << ", " << hitspp.T3 << ", " << hitspp.T4 << endl;

        SaetasData saetad;
        saetad = saetas_counter(saetas_carray, rpc_saeta, hitspp.ind_k);
        cout << saetad.number << " Saetas, with best Chi2: " << saetad.chi_2 << endl;

        // Get MIDAS values
        ReturnMIDAS values = particle_midas(5.67, 5, 3);
        cout << "ID: " << values.id << ", Hello " << c_z0_plane[0] << endl;

        cout << "\n\n" << endl;
        cout << "\n\n" << endl;
    }
}


