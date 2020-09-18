#ifndef TACTIVECELLS
#define TACTIVECELLS

#include "TObject.h"
#include "TH2D.h"
#include "TFile.h"


//using namespace std;
class TActiveCells: public TObject
{
protected:
    TH2D* h_active_cells[4][4];    //!- 4 years (2015-2018) x 4 detectors
    TFile* fInPar;

public:
    TActiveCells();
    TActiveCells(TString filename);
    ~TActiveCells() {
	for(Int_t i=0;i<4;i++) {
	    for(Int_t j=0;j<4;j++) {
		delete h_active_cells[i][j];
	    }
	}
        delete fInPar;
    }
    Bool_t isCellActive(Int_t year, Float_t doy, Int_t detector, Int_t cell);

public:
    ClassDef(TActiveCells,0)
};

#endif /* !TACTIVECELLS */