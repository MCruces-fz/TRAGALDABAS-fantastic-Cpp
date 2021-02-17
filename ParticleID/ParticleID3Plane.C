
// -------------------------------------------------- //
//       -------   H O W   T O   U S E   -------      //
//                                                    //
//           $ root -l                                //
//           root [0] .L ParticleID3Plane.C           //
//           root [1] Saetas3Planes()                 //
//                                                    //
// -------------------------------------------------- //

#include <iostream>
#include <string>
#include <tuple>
#include <libgen.h>
#include <stdio.h>

#include "TH1F.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TTree.h"
#include "TChain.h"
#include "TLine.h"
#include "TText.h"
#include "TLegend.h"
#include "TFile.h"

using namespace std;

struct ReturnMIDAS {
    /*
     *   This is the definition of the
     * structure of the ParticleMIDAS
     * function return.
     */

    Int_t   ID;    // Particle Identification
    Float_t P_ID;  // Probability of ID
    Float_t E_m;   // Minimum energy
    Float_t E_M;   // Maximum energy
    Float_t P_E_m; // Probability of E_m
    Float_t P_E_M; // Probability of E_M
};

ReturnMIDAS ParticleMIDAS(Float_t Chi2, Float_t AnAlg, Int_t MultTotAlg) {
    /*
     *       __  __ ___ ____    _    ____
     *      |  \/  |_ _|  _ \  / \  / ___|
     *      | |\/| || || | | |/ _ \ \___ \
     *      | |  | || || |_| / ___ \ ___) |
     *      |_|  |_|___|____/_/   \_\____/
     *
     *       //------------------------\\
     *      // Author of the Algorithm: \\
     *      \\   Yanis Fontenla Barba   //
     *       \\------------------------//
     *
     *   This program classifies each particle according
     * to its input parameters.
     *
     *   Flowchart for the MIDAS particles identification
     * algorithm in the Tragaldabas detector. The solution
     * procedure when 3 active RPC planes is shown.
     *
     * Parameters:
     *   - Float_t Chi2: Chi square value of the track
     *   - Float_t AnAlg: Weighted multiplicity
     *   - Int_t   MultTotAlg: Number of hits in all planes in each event
     *
     * Return:
     *   - struct ReturnMIDAS{
     *         Int_t   ID;    // Particle Identification
     *         Float_t P_ID;  // Probability of ID
     *         Float_t E_m;   // Minimum energy
     *         Float_t E_M;   // Maximum energy
     *         Float_t P_E_m; // Probability of E_m
     *         Float_t P_E_M; // Probability of E_M
     *     }
     */

    Int_t Id=0;
    Float_t P_Id=0, E_min=0, E_max=0, P_Id_Max=0, P_Id_Min=0;

    if(Chi2 >= 6){
        Id   = 11; // electron
        P_Id = 0.886;
        if(AnAlg >= 6){
            E_min    = 0.0178; // 17.8 MeV
            E_max    = 5;
            P_Id_Min = 0.0002; // 0.02 %
            P_Id_Max = 0.999;
        }else{ // AnAlg < 6
            if(MultTotAlg >= 4){
                E_min    = 0.0316; // 31.6 MeV
                E_max    = 5;
                P_Id_Min = 0.00315; // 0.315 %
                P_Id_Max = 0.999;
            }else{
                E_min    = 0.010;
                E_max    = 5;
                P_Id_Min = 1;
                P_Id_Max = 0.999;
            }
        }
    }else{ // Chi2 < 6
        if(MultTotAlg >= 4){
            Id       = 11;
            P_Id     = 0.998;
            E_min    = 0.0316;
            E_max    = 5;
            P_Id_Min = 0.00315;
            P_Id_Max = 0.999;
        }else if (MultTotAlg == 3) {
            Id       = 13;
            P_Id     = 0.9754;
            E_min    = 0.010;
            E_max    = 5;
            P_Id_Min = 0.9429;
            P_Id_Max = 0.999;
        }else if (MultTotAlg <= 2) {
            Id       = 11;
            P_Id     = 0.628;
            E_min    = 0.010;
            E_max    = 5;
            P_Id_Min = 0.99986;
            P_Id_Max = 0.999;
        }else if (AnAlg >= 6) {
            Id       = 11;
            P_Id     = 0.9973;
            E_min    = 0.0178;
            E_max    = 5;
            P_Id_Min = 0.0002;
            P_Id_Max = 0.999;
        }else if (AnAlg == 5) {
            Id       = 11;
            P_Id     = 0.4266;
            E_min    = 0.0178;
            E_max    = 5;
            P_Id_Min = 0.0054;
            P_Id_Max = 0.999;
        }else if (AnAlg == 4) {
            Id       = 11;
            P_Id     = 0.9728;
            E_min    = 0.0178;
            E_max    = 5;
            P_Id_Min = 0.0012;
            P_Id_Max = 0.999;
        }else if (AnAlg <= 3) {
            Id       = 11;
            P_Id     = 0.5304;
            E_min    = 0.010;
            E_max    = 5;
            P_Id_Min = 0.9998;
            P_Id_Max = 0.999;
        }else{
            cout << "MIDAS Error: This particle does not match." << endl;
            exit(-1);
        }
    }

    ReturnMIDAS values = {Id, P_Id, E_min, E_max, P_Id_Min, P_Id_Max};
    return values;
}

void Saetas3Planes(char inputFile[120]) {

    // # TRB indices for each detector plane
    // TRB_TAB = {"T1": 2, "T3": 0, "T4": 1}

    // ---   D E C L A R A T I O N S   --- //
    Int_t rpcHitsPerEvent   = 0;
    Int_t rpcSaetaPerEvent  = 0;

    // Returns of the ParticleMIDAS() function
    Int_t ID;
    Float_t P_ID, E_m, E_M, P_E_m, P_E_M;
    ReturnMIDAS values;

    Float_t chi2 = 10^7, bestChi2;
    Int_t index0 = 0;


    // Heights of planes:
    Float_t heightT1 = 1826, heightT3 = 924, heightT4 = 87;
    Int_t hit1, hit3, hit4;
    Float_t TotMult, a_n = 0;

    Float_t Chi2;

    Bool_t sillyPrints = 0;
    Bool_t outPrints = 1;
    // ----------------------------------- //

    // READING TREE
//    char inputFile[120] = "/home/mcruces/Documents/multi_analysis/tr20092001740.hld.root.root";
    string fullname = inputFile;
    string filename = fullname.substr(2,11);
    TFile *tFile = TFile::Open(inputFile);
    TTree* tree = (TTree*)tFile->Get("T");

    //Crystal Points (input)   -------------------------------------------------
    TClonesArray* rpcHitCA;
    TRpcHit** rpcHit;
    rpcHitCA = new TClonesArray("TRpcHit", 5);
    TBranch *branchTRpcHit = tree ->GetBranch("rpchit");  // RPCHit  rpchit
    branchTRpcHit->SetAddress(&rpcHitCA); // TODO: What is the meaning of this?

    //----   RPCSaeta (input)   -------------------------------------------------
    TClonesArray* rpcSaetaCA;
    TRpcSaeta** rpcSaeta;
    rpcSaetaCA = new TClonesArray("TRpcSaeta", 5);
    TBranch *branchTRpcSaeta = tree ->GetBranch("RpcSaeta3Planes");
    branchTRpcSaeta->SetAddress(&rpcSaetaCA);

    //---------------------------------------------------------------------------


    Long64_t nevents = tree->GetEntries();

//    // OUTPUT FILE
//    fstream OutFile;
//    OutFile.open("EstudEstad_4planosSinEdificio_M.txt", fstream::out);
//    OutFile << "Id_PartPrimaria" << "\t" << "Energia_PartPrimaria [GeV]" << "\t" <<
//    "Chi-Square" << "\t" << "a_n" << "\t" << "M_{Tot}" << "\t" <<
//    "M1" <<"\t"<< "M2" << "\t" << "M3" << "\t" << "M4" << endl;

    if (sillyPrints) cout << "Number of Events: " << nevents << endl;

    // Defined Counters:
    Int_t n00Id = 0;  // Number of particles with Id = 0
    Int_t n_indexNon0 = 0;  // Number of getInd() != 0

    //LOOP ON EVENTS
    for (int i = 0; i < nevents; i++) {

        if (sillyPrints) cout << "\n\n@ === EVENT " << i << " === @\n" << endl;

        tree->GetEvent(i);
        rpcHitsPerEvent = rpcHitCA->GetEntries();
        rpcSaetaPerEvent = rpcSaetaCA->GetEntries();

        // Clear multiplicity variables
        hit1=0, hit3=0, hit4=0;
        TotMult = 0;

        if (rpcHitsPerEvent > 0) {
            rpcHit = new TRpcHit*[rpcHitsPerEvent];

            // LOOP ON HITS ON EACH EVENT
            for (Int_t k = 0; k < rpcHitsPerEvent; k++) {

                rpcHit[k] = new TRpcHit;
                rpcHit[k] = (TRpcHit*) rpcHitCA->At(k);

                TotMult++;
                Float_t Z0 = rpcHit[k]->getZ(); // FIXME: Loading twice fails!!

                if(Z0 == heightT1) {
                    hit1++; // Plane T1
                } else if (Z0 == heightT3) {
                    hit3++; // Plane T3
                } else if (Z0 == heightT4) {
                    hit4++; // Plane T4
                } else {
                    cout << "Planes at: " << heightT1 << " mm, " << heightT3  << " mm, " << heightT4  << " mm" << endl;
                    cout << "Current height: " << Z0 << endl;
                    exit(-1);
                }
            }
        } else { 
            continue; // Save hits only if they're in all planes:
        }

        a_n = hit1 * 0 + hit3 * 2 + hit4 * 3;
        rpcSaeta = new TRpcSaeta*[rpcSaetaPerEvent];

        if (sillyPrints) cout << "Hits: (" << hit1 << ", " << hit3 << ", " << hit4 << ")" << endl;
        if (sillyPrints) cout << "   Total multiplicity: " << TotMult << endl;
        if (sillyPrints) cout << "Weighted multiplicity: " <<     a_n << endl;

        // Clear saeta variables
        index0 = 0;
        ID = -1;
        bestChi2 = 1000;

        if (sillyPrints) cout << "\nNumber of Saetas: " << rpcSaetaPerEvent << endl;
        if (sillyPrints) cout << "Indices in the TClonesArray:" << endl;


        // LOOP ON NUMBER OF SAETAS ON EACH EVENT

        if ( rpcSaetaPerEvent == 0 ) continue;  // Save hits only if there are saetas.

        for(Int_t j = 0; j < rpcSaetaPerEvent; j++){
            rpcSaeta[j] = new TRpcSaeta;
            rpcSaeta[j] = (TRpcSaeta*) rpcSaetaCA->At(j);

            chi2 = rpcSaeta[j]->getChi2();
            if (chi2 < bestChi2) bestChi2 = chi2;

            // Indices of the hits of the saeta in the TClonesArray
            if (sillyPrints) {
            cout << "Saeta[" << j << "] -> (" << rpcSaeta[j]->getInd(2) // T1 -> TRB 2
                                      << ", " << rpcSaeta[j]->getInd(0) // T3 -> TRB 0
                                      << ", " << rpcSaeta[j]->getInd(1) // T4 -> TRB 1
                                      << "), chi2 = " << chi2 << endl; 
            }
        }

        // Getting ParticleMIDAS information
        values = ParticleMIDAS(bestChi2, a_n, TotMult);
        ID    = values.ID;    // Particle Identification
        P_ID  = values.P_ID;  // Probability of ID
        E_m   = values.E_m;   // Minimum energy
        E_M   = values.E_M;   // Maximum energy
        P_E_m = values.P_E_m; // Probability of E_m
        P_E_M = values.P_E_M; // Probability of E_M

        if (sillyPrints) {
        if (ID == 13) cout << "-------------------------------------------------------" << endl;
        cout << "Parameters of ParticleMIDAS: " << bestChi2 << ", " << a_n << ", " << TotMult << endl;
        cout << "Particle ID: " << ID << ", P(ID) = " << P_ID << ", Chi2(ID) = " << bestChi2 << endl;
        if (ID == 13) cout << "-------------------------------------------------------" << endl;
        }

        if (outPrints) {
            cout << filename << "," << i << ","  << ID << "," << P_ID << "," << bestChi2  << "," << hit1 << "," << hit3 << "," << hit4 << endl;
        }
    }
    if (sillyPrints) cout << "END without errors!" << endl;
}
