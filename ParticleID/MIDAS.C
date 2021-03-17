
using namespace std;

struct ReturnMIDAS {
    /*
     *   This is the definition of the
     * structure of the ParticleMIDAS
     * function return.
     */

    Int_t   id;    // Particle Identification
    Float_t p_id;  // Probability of id 
    Float_t e_min;   // Minimum energy
    Float_t e_max;   // Maximum energy
    Float_t p_e_min; // Probability of e_min
    Float_t p_e_max; // Probability of e_max
};

ReturnMIDAS particle_midas(Float_t Chi2, Float_t AnAlg, Int_t MultTotAlg) {
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
            // Id       = 11;
            // P_Id     = 0.4266;
            Id       = 13;
            P_Id     = 0.57300;
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
