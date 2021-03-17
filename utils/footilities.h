#ifndef FOOTILITIES_H
#define FOOTILITIES_H

#include <list> // ind_k and iterator

#include "../ParticleID/bad_cells.h"
#include "constants.h"

// using namespace std;

Int_t c_constant =12;

struct TrbID {

    /*
     *    Integer identification for each
     * plane of the detector.
     */

    Int_t T1 = 2;
    Int_t T3 = 0;
    Int_t T4 = 1;
};


// Int_t [2] to_col_row(Int_t cell) {
//     return cell % c_ncol, cell / c_ncol + 1;
// }

Int_t to_cell(Int_t col, Int_t row) {
    return c_ncol * (row - 1) + col;
}


struct HitsPerPlane {
    Int_t T1, T3, T4;
    list<int> ind_k;
};

HitsPerPlane hits_topology(TClonesArray* hits_carray, TRpcHit** hit, ReturnBC bc) {

    Int_t nhits = hits_carray -> GetEntries();
    hit = new TRpcHit*[nhits];

    TrbID trb_id;

    Int_t hits1 = 0, hits3 = 0, hits4 = 0;  
    list<Int_t> ind_k ;


    for (Int_t k = 0; k < nhits; k++) {

        hit[k] = new TRpcHit;
        hit[k] = (TRpcHit*) hits_carray -> At(k);

        Int_t trb_num = hit[k] -> getTrbnum();
        Int_t cell = hit[k]->getCell();

        if (silly_prints) cout << "Trbnum: " << hit[k] -> getTrbnum() << ", cell: " << cell << endl;

        if (trb_num == trb_id.T1) {
            hits1++;
            for (int c = 0; c < 20; c++) {
                if (cell == bc.T1[c]) {
                    ind_k.push_back(k);
                    hits1--;
                    if (silly_prints) cout << "Cell " << cell << " is wrong, k index: " << k << endl;
                }
            }
        } else if (trb_num == trb_id.T3) {
            hits3++;
            for (int c = 0; c < 20; c++) {
                if (cell == bc.T3[c]) {
                    ind_k.push_back(k);
                    hits3--;
                    if (silly_prints) cout << "Cell " << cell << " is wrong, k index: " << k << endl;
                }
            }
        } else if (trb_num == trb_id.T4) {
            hits4++;
            for (int c = 0; c < 20; c++) {
                if (cell == bc.T4[c]) {
                    ind_k.push_back(k);
                    hits4--;
                    if (silly_prints) cout << "Cell " << cell << " is wrong, k index: " << k << endl;
                }
            }
        }

    }

    HitsPerPlane values = {hits1, hits3, hits4, ind_k};
    return values;
}


struct SaetasData{
    Int_t number;
    Float_t chi_2;
};

SaetasData saetas_counter(TClonesArray* saetas_carray, TRpcSaeta** saeta, list<Int_t> ind_k) {

    Int_t nsaetas= saetas_carray -> GetEntries();
    saeta = new TRpcSaeta*[nsaetas];

    SaetasData saetad;

    Bool_t del_saeta;
    Float_t chi_2;
    Float_t best_chi2 = 10000.;
    Int_t index0 = 0, ID = -1;

    list<int>::iterator it;

    for (Int_t k = 0; k < nsaetas; k++) {

        saeta[k] = new TRpcSaeta;
        saeta[k] = (TRpcSaeta*) saetas_carray -> At(k);

        chi_2 = saeta[k] -> getChi2();

        if (silly_prints) cout << "Chi2: " << chi_2 << endl;

        Int_t sindT1 = saeta[k] -> getInd(2);
        Int_t sindT3 = saeta[k] -> getInd(0);
        Int_t sindT4 = saeta[k] -> getInd(1);

        del_saeta = 0;

        for (it=ind_k.begin(); it!=ind_k.end(); ++it) {
            if (silly_prints) cout << "Iterator: " << *it << endl;
            if (sindT1 == *it or sindT3 == *it or sindT4 == *it){
                chi_2 = 99999;
                del_saeta = 1;
                if (silly_prints) cout << "Saeta deleted with " << *it << endl;
            }
        }

        if (del_saeta == 1) nsaetas--;
        if (chi_2 < best_chi2) best_chi2 = chi_2;
    }


    SaetasData values = {nsaetas, best_chi2};
    return values;
}

#endif 
