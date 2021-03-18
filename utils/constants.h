#ifndef CONSTANTS_H
#define CONSTANTS_H

using namespace std;

// Directories:
string c_bc_dir = "/home/mcruces/Documents/GitHub/TRAGALDABAS-fantastic-Cpp/BadCells/";
string c_root_dir = "/home/mcruces/Documents/fptrucha_hits/root/";

// Heights of planes:
Float_t heightT1 = 1826, heightT2 = 1304, heightT3 = 924, heightT4 = 87;
Int_t c_z0_plane [4] = {1826, 1304, 924, 87};  // T1, T2, T3, T4

// Number of columns and rows
Int_t c_ncol = 12;
Int_t c_nrow = 10;

Bool_t silly_prints = 0;
Bool_t out_prints   = 1;

#endif 
