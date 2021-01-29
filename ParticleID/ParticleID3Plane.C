
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


float ParticleMIDAS(float Chi2, float AnAlg, int MultTotAlg) {
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
     * Parameters:
     *   - Chi2: Chi square value of the track
     *   - AnAlg: Weighted multiplicity
     *   - MultTotAlg: Number of hits in all planes in each event
     *
     * Return:
     *   - Id: Particle identification
     */

    Int_t Id=0;
    Float_t al_m=0, P_Id=0, E_min=0, E_max=0, P_Id_Max=0, P_Id_Min=0, Id_mctrack=0, IdMC=0;

    if(Chi2>=6){
        Id   = 11; //electron
        P_Id = 0.886;
        if(AnAlg>=6){
            E_min    = 0.00178;
            E_max    = 5;
            P_Id_Min = 0.0002;
            P_Id_Max = 0.999;
        }else{
            if(MultTotAlg>=4){
                E_min    = 0.00316;
                E_max    = 5;
                P_Id_Min = 0.0315;
                P_Id_Max = 0.999;
            }else{
                E_min    = 0.010;
                E_max    = 5;
                P_Id_Min = 1;
                P_Id_Max = 0.999;
            }
        }
    }else{
        if(MultTotAlg>=4){
            Id       = 11;
            P_Id     = 0.998;
            E_min    = 0.0316;
            E_max    = 5;
            P_Id_Min = 0.00315;
            P_Id_Max = 0.999;
        }else{
            if(MultTotAlg<=2){
                Id       = 11;
                P_Id     = 0.628;
                E_min    = 0.010;
                E_max    = 5;
                P_Id_Min = 0.99986;
                P_Id_Max = 0.999;
            }else{
                if(AnAlg>=6){
                    Id       = 11;
                    P_Id     = 0.9973;
                    E_min    = 0.0178;
                    E_max    = 5;
                    P_Id_Min = 0.0002;
                    P_Id_Max = 0.999;
                }else{
                    if(MultTotAlg==5){
                        Id       = 11;
                        P_Id     = 0.4266;
                        E_min    = 0.0178;
                        E_max    = 5;
                        P_Id_Min = 0.0054;
                        P_Id_Max = 0.999;
                    }else{
                        if(MultTotAlg==5){
                            Id       = 11;
                            P_Id     = 0.4266;
                            E_min    = 0.0178;
                            E_max    = 5;
                            P_Id_Min = 0.0054;
                            P_Id_Max = 0.999;
                        }else{
                            if(AnAlg<=3){
                                Id       = 11;
                                P_Id     = 0.5304;
                                E_min    = 0.010;
                                E_max    = 5;
                                P_Id_Min = 0.9998;
                                P_Id_Max = 0.999;
                            }else{
                                Id       = 13;
                                P_Id     = 0.9754;
                                E_min    = 0.100;
                                E_max    = 5;
                                P_Id_Max = 0.999;
                                P_Id_Min = 0.9429;
                            }
                        }
                    }
                }
            }
        }
    }

    return Id;
}

void Saetas3Planes() {

    // ---   D E C L A R A T I O N S   --- //
    Int_t rpcHitsPerEvent   = 0;
    Int_t rpcSaetaPerEvent  = 0;

    // Heights of planes:
    Float_t heightT1 = 1826, heightT3 = 924, heightT4 = 87;

    Float_t TotMult = 0, a_n = 0;

    Float_t Chi2;

    // INPUT FILE
    char inputFile[120] = "/home/mcruces/Documents/multi_analysis/tr20092001740.hld.root.root";
    TFile *tFile = TFile::Open(inputFile);

    // READING TREE
    TTree* tree = (TTree*)tFile->Get("T");

    //Crystal Points (input)   -------------------------------------------------
    TClonesArray* rpcHitCA;
    TRpcHit** rpcHit;
    rpcHitCA = new TClonesArray("TRpcHit", 5); // Change 5000!!!
    TBranch *branchTRpcHit = tree ->GetBranch("rpchit");  // RPCHit  rpchit
    branchTRpcHit->SetAddress(&rpcHitCA); // TODO: What is the meaning of this?

    //----   RPCSaeta (input)   -------------------------------------------------
    TClonesArray* rpcSaetaCA;
    TRpcSaeta** rpcSaeta;
    rpcSaetaCA = new TClonesArray("TRpcSaeta", 5);
    TBranch *branchTRpcSaeta = tree ->GetBranch("RpcSaeta3Planes");  // RPCSaeta     RpcSaeta3Planes
    branchTRpcSaeta->SetAddress(&rpcSaetaCA);

    //---------------------------------------------------------------------------


    Long64_t nevents = tree->GetEntries();

    // OUTPUT FILE
    fstream OutFile;
    OutFile.open("EstudEstad_4planosSinEdificio_M.txt", fstream::out);
    OutFile << "Id_PartPrimaria" << "\t" << "Energia_PartPrimaria [GeV]" << "\t" <<
    "Chi-Square" << "\t" << "a_n" << "\t" << "M_{Tot}" << "\t" <<
    "M1" <<"\t"<< "M2" << "\t" << "M3" << "\t" << "M4" << endl;

    cout << "Number of Events: " << nevents << endl;

    //LOOP ON EVENTS
    for (int i = 0; i < nevents; i++) {

        tree->GetEvent(i);
        rpcHitsPerEvent = rpcHitCA->GetEntries();
        rpcSaetaPerEvent = rpcSaetaCA->GetEntries();

        Int_t hit1=0, hit3=0, hit4=0;

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
            cout << "Event " << i << ", hits: (" << hit1 << ", " << hit1 << ", " << hit1 << ")" << endl;
        }

        a_n = hit1 * 0 + hit3 * 2 + hit4 * 3;
        rpcSaeta = new TRpcSaeta*[rpcSaetaPerEvent];

//        rpcSaeta[0] = new TRpcSaeta;
//        rpcSaeta[0] = (TRpcSaeta*) rpcSaetaCA->At(0);
//        Float_t chiVal = rpcSaeta[0]->getChi2();
//        cout << "----------- Evt " << i << ", Chi2 = " << rpcSaeta[0]->getChi2() << endl;

    }

}
