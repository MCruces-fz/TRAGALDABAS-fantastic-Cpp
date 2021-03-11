#include "MIDAS.C"
#include "BadCells.h"
#include "../Utils/Const.h"
#include "../Utils/Utilities.h"

using namespace std;

void EventTopology() {

    // Date Constants:
    string yy = "20";
    string doy = "270";
    string yydoy = yy + doy;

    // Filenames:
    // --> Bad cells
    string bc_filename = "bad_cells_" + yydoy + ".csv";
    // --> Root file
    string root_filename = "tr20259084207.hld.root.root";

    // Full Paths:
    // --> Bad cells
    string bc_fulll_path = c_bc_dir + bc_filename;
    // --> Root file
    string root_full_path = c_root_dir + root_filename;

    // Read Bad Cells:
    ReturnBC bad_cells = read_bad_cells(bc_fulll_path);
    cout << "Bad cells of 20270: " << bad_cells.T1[0] << endl;

    // Read TFile:
    // (It needs a char as input)
    int lenPath = root_full_path.length();
    char root_char_path[lenPath + 1];
    strcpy(root_char_path, root_full_path.c_str());
    TFile* t_file = new TFile(root_char_path, "READ");

    // Read TTree:
    TTree* tree  = (TTree*) t_file -> Get("T");

    // Get MIDAS values
    ReturnMIDAS values = particle_midas(5.67, 5, 3);
    cout << "ID: " << values.id << ", Hello " << c_z0_plane[0] << endl;

    Long64_t nevents = tree->GetEntries();
    cout << "Number of events: " << nevents << endl;

    //--  Reading TClonesArrays -------------------------------------
    //----  Hits
    TClonesArray* hits_carray;  // Declared TClonesArray
    hits_carray = new TClonesArray("TRpcHit");  // Defined TClonesArray of TRpcHit objects

    TBranch *branch_rpchit = tree -> GetBranch("rpchit");  // Defined rpchit branch as pointer
    branch_rpchit -> SetAddress(&hits_carray); // Set TRpcHit objects of rpchit for hits_carray TClonesArray

    TRpcHit** rpc_hit;  // Declared instance of TRpcHit class

    //----  Saetas
    TClonesArray* saetas_carray;
    saetas_carray = new TClonesArray("TRpcSaeta");

    TBranch *branch_rpcsaeta = tree -> GetBranch("RpcSaeta3Planes");
    branch_rpcsaeta -> SetAddress(&saetas_carray);

    TRpcSaeta** rpc_saeta;
    //----------------------------------------------------------------

}


