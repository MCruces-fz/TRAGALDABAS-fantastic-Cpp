
#include "efficiency.h"
#include "tunpacker.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "thldevent.h"
#include "tevent.h"
#include "TString.h"
#include "thit.h"
#include "trpclookuptable.h"
#include "trpcrawf.h"
#include "trpchitf.h"
#include "trpcraw.h"
#include "trpchit.h"
#include "trpcsaetafh"
#include "trpcsaeta.h"
#include "ttmatrix.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TF1.h"
#include "TTree.h"
#include <fstream>
#include "TTimeStamp.h"
#include "TMath.h"
#include <algorithm>
#include <vector>
//#include <ofstream>


using namespace std;


//______________________________________________________________________________
Filler::Filler()
{
	EventNr   = 0;
	pEvent    = 0;
	pRootFile = 0;
	subEvtId  = 0;
	fpga_code = 0;
	refCh     = -1;

	fTheta_intervals[0] = 0.;
	fTheta_intervals[1] = 1.29209663815835789e+01;
	fTheta_intervals[2] = 1.84349488229220171e+01;
	fTheta_intervals[3] = 2.27864979995971453e+01;
	fTheta_intervals[4] = 2.65650511770779936e+01;
	fTheta_intervals[5] = 3.00000000000000036e+01;
	fTheta_intervals[6] = 60.;

	/*
	for(Int_t i=0;i<3;i++) {
	for(Int_t j=0;j<12;j++) {
	   h_y_x_theta[i][j]    = new TH2D(Form("h_y_x_%i_theta_%i",i,j),Form("h_y_x_%i_theta_%i;x [mm];y [mm]",i,j),400,-800,800,400,-800,800);
	}
	}
	*/

	for(Int_t i=0;i<2;i++) {
		h_eff[i] = new TH2D(Form("h_eff_%i",i),Form("h_eff_%i",i),366*24*6,0.,366.,10,-1000,1000);
		//Una por HORA!
		h_theta_time[i] = new TH2D(Form("h_theta_time_%i",i),Form("h_theta_time_%i",i),366*24,0.,366,60,0,60);
		h_eff_nn[i] = new TH1D(Form("h_eff_nn_%i",i),Form("h_eff_nn_%i",i),366*24*6,0.,366.);
	}

	for(Int_t i=0;i<3;i++) {
		h_cell_counts[i]      = new TH2D(Form("h_cell_counts_h%i",i),Form("h_cell_counts_h%i",i),366*24,0.,366,120,0,120);
		h_cell_counts_n1[i]   = new TH2D(Form("h_cell_counts_n1_h%i",i),Form("h_cell_counts_n1_h%i",i),366*24,0.,366,120,0,120);
		h_cell_counts_n2[i]   = new TH2D(Form("h_cell_counts_n2_h%i",i),Form("h_cell_counts_n2_h%i",i),366*24,0.,366,120,0,120);
		h_n_q[i]              = new TH2D(Form("h_n_q_H%i",i),Form("h_n_q_H%i;#sum Q  [a.u.]; N hits",i),4000,0,40000,120,0,120);
		h_n_q_clean[i]        = new TH2D(Form("h_n_q_clean_H%i",i),Form("h_n_q_clean_H%i;#sum Q  [a.u.]; N hits",i),4000,0,40000,120,0,120);

		//Has to be normalized anyway to daq!
		h_log10q_flux[i]      = new TH2D(Form("h_log10q_flux_H%i",i),Form("h_log10q_flux_H%i",i),366,0,366,50,0,5);
		h_nhits_flux[i]       = new TH2D(Form("h_nhits_flux_H%i",i),Form("h_nhits_flux_H%i",i),2*366,0,366,60,0,120);
	}

	for(Int_t i=0;i<6;i++) {
		for(Int_t j=0;j<6;j++) {
			// 10 min time bin x 15 deg phi bin
			h_flux3[i][j] = new TH2D(Form("h_flux3_M_%i_Theta_%i",i,j),Form("h_flux3_M_%i_Theta_%i",i,j),366*24*6,0.,366.,24,-180.,180.);
			h_flux2[i][j] = new TH2D(Form("h_flux2_M_%i_Theta_%i",i,j),Form("h_flux2_M_%i_Theta_%i",i,j),366*24*6,0.,366.,24,-180.,180.);
		}
	}

	h_daq_active     = new TH1D("h_daq","h_daq;D.O.Y.;Frequency",366*24*6,0.,366.);
	h_daq_sync       = new TH1D("h_daq_sync","h_daq_sync;D.O.Y.;Frequency",366*24*6,0.,366.);
	h_daq_seconds    = new TH1D("h_daq_seconds","h_daq_seconds;D.O.Y.;Frequency",366*24*6,0.,366.);
	h_daq_total      = new TH1D("h_daq_total","h_daq_total;D.O.Y.;Frequency",366*24*6,0.,366.);

	h_dt_1 = new TH1D("h_dt_1","h_dt_1",1000,-40,40);
	h_dt_2 = new TH1D("h_dt_2","h_dt_2",1000,-40,40);

	h_dt_cell_1 = new TH2D("h_dt_cell_1","h_dt_cell_1",120,0,120,100,-20,20);
	h_dt_cell_2 = new TH2D("h_dt_cell_2","h_dt_cell_2",120,0,120,100,-20,20);

	/*
	for(Int_t i=0;i<10;i++) {
	for(Int_t j=0;j<12;j++) {
	    for(Int_t k=0;k<10;k++) {
		for(Int_t l=0;l<12;l++) {
		    hdt[i*12*10*12+j*10*12+k*12+l] = new TH1D(Form("h_dt_r1_%i_c1_%i_r2_%i_c2_%i",i,j,k,l),
					       Form("h_dt_r1_%i_c1_%i_r2_%i_c2_%i",i,j,k,l),
					       250,-20,20);
		}
	    }
	}
	}
	hdt[10*12*10*12] = new TH1D("h_dt_all","h_dt_all;Dt [ns];entries",500,-80,80);
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////
}

void Filler::fillHistograms(const char* dir, TString list, const char* odir,const char* ofile, Int_t nEvt,Int_t n)
{
//    TFile* fOut = new TFile(ofile,"RECREATE");
    TFile fOut(Form("%s%s",odir,ofile),"RECREATE");
    refCh = -1;
    refCh = 31;
    this->subEvtId= 0;
    cout<<"ofile "<<outputFile<<endl;
    std::ifstream file(list.Data());
    TString fName;
    while(!file.eof()) {
	file>>fName;
        cout<<" file  "<<fName<<" directory "<<dir<<endl;
	if(!fName||!fName.Contains("hld"))break;
	setInputFile(dir,fName.Data());
	EventNr=0;
	pEvent = new HldEvent(inputFile.c_str(), 999, " ", -100000,100000);
	pEvent->setQuietMode(true);
	pEvent->setFullSetup(true);
	pEvent->setVHR(false);
	pEvent->setDebugFlag(0);
	pEvent->setDebugFlag1(0);
        pRootFile=0;
	if(nEvt>0)
	{
	    eventLoopFill(nEvt,0);
	}
	delete pEvent;
        pEvent = NULL;
    }

    file.close();
    fOut.cd();

    // Do your staff to the histograms

    h_dt_1 -> Write();
    h_dt_2 -> Write();

    h_dt_cell_1 -> Write();
    h_dt_cell_2 -> Write();

    for(Int_t i=0;i<2;i++) {
        h_eff_nn[i] -> Write();
	h_eff[i]->Write();
	h_theta_time[i]->Write();

    }
    for(Int_t i=0;i<6;i++) {
	for(Int_t j=0;j<6;j++) {
	    h_flux3[i][j]->Write();
	    h_flux2[i][j]->Write();
	}
    }
    h_daq_active  -> Write();
    h_daq_sync    -> Write();
    h_daq_seconds -> Write();
    h_daq_total   -> Write();

    for(Int_t i=0;i<3;i++) {
	h_cell_counts[i]    -> Write();
	h_cell_counts_n1[i] -> Write();
	h_cell_counts_n2[i] -> Write();
	h_n_q[i] -> Write();
	h_n_q_clean[i] -> Write();
        h_log10q_flux[i] -> Write();
        h_nhits_flux[i]  -> Write();

    }
    /*
    for(Int_t i=0;i<3;i++) {
        for(Int_t j=0;j<12;j++) {
            h_y_x_theta[i][j] -> Write();
        }
    }
    */

    /*
    for(Int_t i=0;i<10;i++) {
        for(Int_t j=0;j<12;j++) {
            for(Int_t k=0;k<10;k++) {
                for(Int_t l=0;l<12;l++) {
                    hdt[i*12*10*12+j*10*12+k*12+l]->Write();
                }
            }
        }
    }
    */

    fOut.Close();
}

//______________________________________________________________________________
Filler::~Filler()
{
	if(pEvent)	delete pEvent;
	if(pRootFile)	delete pRootFile;

	// Delete all your histograms!

}

//______________________________________________________________________________
Bool_t Filler::setRootFile(const char* filename/*="test.root" */)
{
	if(pRootFile){
		  delete pRootFile;
		  pRootFile=new TFile(filename,"RECREATE");	  
	}
	else	pRootFile=new TFile(filename,"RECREATE");	  

	return kTRUE;
}
 
//______________________________________________________________________________
string Filler::setInputFile(const char* dir,const char* filename)
{
	stringstream Name(Form("%s%s",dir,filename));
	string Tmp,NoWhite;
	//it strips all whitespaces from name
	while(!Name.eof())
	{
		Tmp.clear();
		Name>>skipws >>Tmp;
		NoWhite+=Tmp;
	}
	inputFile=NoWhite;  
	return inputFile;
}

string Filler::setInputFile(const char* filename)
{
	stringstream Name(filename);
	string Tmp,NoWhite;
	//it strips all whitespaces from name
	while(!Name.eof())
	{
		Tmp.clear();
		Name>>skipws >>Tmp;
		NoWhite+=Tmp;
	}
	inputFile=NoWhite;  
	return inputFile;
}
	
//______________________________________________________________________________
Bool_t Filler::setpEvent(Int_t Id)
//Id is the subevent id 
{
	if(inputFile.empty())
	{
		return kFALSE;
	}
	subEvtId=Id;
	return kTRUE;
}

//______________________________________________________________________________
Bool_t Filler::eventLoopFill(Int_t nbEvt, Int_t startEv)
//Loop over all events, data written to the root tree
{
    if(pEvent==0)
    {
        cout<<"Error: no pEvent set"<<endl;
        return kFALSE;
    }
    else
    {
        cout<<"loading lookup "<<fileLookupPar<<endl;

        Int_t trbnum, cell, col, row;
        Float_t     x, y, z;
        Float_t time, charge;

        Int_t trbnum2, cell2, col2, row2;
        Float_t     x2, y2, z2;
        Float_t time2, charge2;

        // Will execute the unpacker
        Event* event = new Event();

        // Will execute the calibrater
        TRpcRawF* rawFinder = new TRpcRawF();
        rawFinder -> init(fileLookupPar);

        RpcLookupTable* fLookPar = new RpcLookupTable(fileLookupPar);

        // Will execute the hit finder
        TRpcHitF* calFinder = new TRpcHitF();
        //calFinder -> init(fileHitFinderPar,"/media/Datos2TB/korna/tragaldabas/pars/active_cells_2015_2016.root");
        calFinder -> init(fileHitFinderPar,"/media/Datos2TB/damian/tragaldabas/soft/GoodActiveCells_2015_2018.root");

        // Will execute the track finder and
        // the three planes track finder!
        TRpcSaetaF* trackFinder = new TRpcSaetaF();
        trackFinder->init();

        // Pointers to the clonesarray of every category of data
        TClonesArray*  rpchits          = rawFinder->getRpcRawHits();
        TClonesArray*  rpccalhits       = calFinder->getRpcHits();
        TClonesArray*  RpcSaeta2Planes  = trackFinder->getRpcSaeta2Planes();
        TClonesArray*  RpcSaeta3Planes  = trackFinder->getRpcSaeta3Planes();
        TClonesArray*  rpccalhitscorr   = trackFinder->getRpcHitCorr();

        TClonesArray* hits = event->getHits();

        Bool_t sync = kTRUE;

        Int_t prevsec = -100;

        for(Int_t i=0; i< nbEvt; i++)
        {
            if(!(pEvent->execute())) // The important business happens here!
            {
                cout<<"END OF FILE"<<endl;
                cout<<"Number of Events: "<<EventNr<<endl;
                break;
            }
            if(!event)
                event = new Event(*pEvent, refCh);
            event->clearAll();
            event->fill(*pEvent);

            event        -> setSync(sync);
            rawFinder    -> execute();
            sync = event -> getSync();
            calFinder    -> execute();
            trackFinder  -> execute();

            Double_t timeEvt = TTimeStamp::GetDayOfYear(event->getEvtDay(),event->getEvtMonth(),event->getEvtYear());
            timeEvt+= event->getEvtHour()/24.;
            timeEvt+= event->getEvtMinute()/24./60.;
            timeEvt+= event->getEvtSecond()/24./60./60.;
            
            h_daq_total    -> Fill(timeEvt);

            // histogram with all events.
            // Then the unsyncronized will be obtained by subtraction

            // Do not include event out of sync!
            if(!sync) {
                h_daq_sync->Fill(timeEvt);
                continue;
            }
            TClonesArray*  fTrbHits = gEvent->getHits();
            Int_t ntrb = fTrbHits->GetEntriesFast();
            Bool_t sinc1=0;
            Bool_t sinc2=0;
            Bool_t sinc3=0;
            for(Int_t i=0;i<ntrb;i++) {
                Hit* hittrb = (Hit*)fTrbHits->At(i);
                if(!hittrb) continue;
                Int_t trb    = hittrb->getTRBNum();
                Int_t tdc    = hittrb->getTDC();
                Int_t chan   = hittrb->getChannel();
                Int_t trbnum = fLookPar->getDetNum(trb);
                if(trbnum==-1)continue;
                //Float_t time     = hittrb->getLeadTime1();
                //Float_t charge     = hittrb->getWidth();
                //fLookPar -> getParams(trbnum, tdc, chan, cell, col, raw, x, y, z);
                if(trbnum==0&&chan==30&&tdc==1)sinc1=1;
                if(trbnum==1&&chan==30&&tdc==1)sinc2=1;
                if(trbnum==2&&chan==30&&tdc==1)sinc3=1;
            }

            //  Get the DOY with time in decimal units!
            // this is the "number of seconds active"

            //if(prevsec==-100) {
            //    prevsec = event->getEvtSecond();
            //    h_daq_active->Fill(timeEvt);
            //}

            if(prevsec != event->getEvtSecond() ) {
                prevsec = event->getEvtSecond();
                h_daq_seconds  -> Fill(timeEvt);
                //h_daq_active->Fill(timeEvt);
            }

            //if(sinc1 &&sinc2 && sinc3) {
            //    h_daq_active->Fill(timeEvt);
            //}
            if(event->getEvtYear() == 2016 ) {
                if(sinc1 &&sinc2) {
                    h_daq_active->Fill(timeEvt);
                }
            } else {
                if(sinc1 &&sinc2 && sinc3) {
                    h_daq_active->Fill(timeEvt);
                }
            }

            // For loop over TRB hits
            //
            //

            // For loop over cal hits
            //
            //

            // For loop over hits!
            rpccalhits     = calFinder->getRpcHits();
            Int_t nrpchits = rpccalhits->GetEntriesFast();
            TRpcHit* rh    = 0;
            TRpcHit* rh2   = 0;

            // For loop over tracks!
            Int_t ntracks  = RpcSaeta2Planes->GetEntriesFast();

            // For loop over tracks in 3 planes!
            Int_t ntracks3 = RpcSaeta3Planes->GetEntriesFast();

            Float_t theta  = event->getThetaDeg();
            Float_t phi    = event->getPhiDeg();

            Float_t theta3 = event->getThetaDeg3();
            Float_t phi3   = event->getPhiDeg3();

            // Fill the theta distributions for 2 and 3 planes
            // This is needed in order to get the right estimation
            // of efficiencies of the detectors 1, 2 and 3.
            // Also it is important for the determination of the power
            // index in the cos^n(theta) distribution.

            if(ntracks==1)
                h_theta_time[0]-> Fill(timeEvt,theta);
            if(ntracks3==1)
                h_theta_time[1]-> Fill(timeEvt,theta3);

            Int_t thetaBin = 6;

            for(Int_t ti=0;ti<7;ti++) {
                if(theta<fTheta_intervals[ti]) {
                    thetaBin=ti-1;
                    break;
                }
            }
            if(thetaBin>5) thetaBin=5;

            Int_t thetaBin3 = 6;

            for(Int_t ti=0;ti<7;ti++) {
                if(theta3<fTheta_intervals[ti]) {
                    thetaBin3=ti-1;
                    break;
                }
            }

            if(thetaBin3>5) thetaBin3=5;

            Int_t M1 = event->getMultH1();
            Int_t M2 = event->getMultH2();
            Int_t M3 = event->getMultH3();
            Float_t Q1 = event->getChargeH1();
            Float_t Q2 = event->getChargeH2();
            Float_t Q3 = event->getChargeH3();

            if(M1==1 && M2==1) {
                Float_t dt_t1;
                Float_t dt_x1;
                Float_t dt_y1;
                Float_t dt_z1;
                Float_t dt_t2;
                Float_t dt_x2;
                Float_t dt_y2;
                Float_t dt_z2;
                Int_t dt_col;
                Int_t dt_row;
                Int_t dt_col2;
                Int_t dt_row2;
                for(Int_t j=0;j<nrpchits;j++) {
                    TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(j);
                    if(rpchit->getTrbnum()==0) {
                        dt_t1  = rpchit->getTime();
                        dt_x1  = rpchit->getX();
                        dt_y1  = rpchit->getY();
                        dt_z1  = rpchit->getZ();
                        dt_col = rpchit->getCol()-1;
                        dt_row = rpchit->getRow()-1;
                    }
                    if(rpchit->getTrbnum()==1) {
                        dt_t2   = rpchit->getTime();
                        dt_x2   = rpchit->getX();
                        dt_y2   = rpchit->getY();
                        dt_z2   = rpchit->getZ();
                        dt_col2 = rpchit->getCol()-1;
                        dt_row2 = rpchit->getRow()-1;
                    }

                }

                //hdt[dt_row*12*10*12+dt_col*10*12+dt_row2*12+dt_col2]->Fill(dt_t2 - dt_t1 - sqrt( pow((dt_x2-dt_x1),2)
                //                                                                                +  pow((dt_y2-dt_y1),2)
                //                                                                                +  pow((dt_z2-dt_z1),2))/299.792458) ;
                h_dt_1 -> Fill(dt_t2 - dt_t1 - sqrt( pow((dt_x2-dt_x1),2)
                                                    +  pow((dt_y2-dt_y1),2)
                                                    +  pow((dt_z2-dt_z1),2))/299.792458) ;


                h_dt_cell_1 -> Fill(dt_col*10+dt_row, dt_t2 - dt_t1 - sqrt( pow((dt_x2-dt_x1),2)
                                                                           +  pow((dt_y2-dt_y1),2)
                                                                           +  pow((dt_z2-dt_z1),2))/299.792458);

            }
            if(M2==1 && M3==1) {
                Float_t dt_t1;
                Float_t dt_x1;
                Float_t dt_y1;
                Float_t dt_z1;
                Float_t dt_t2;
                Float_t dt_x2;
                Float_t dt_y2;
                Float_t dt_z2;
                Int_t dt_col;
                Int_t dt_row;
                for(Int_t j=0;j<nrpchits;j++) {
                    TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(j);
                    if(rpchit->getTrbnum()==2) {
                        dt_t1  = rpchit->getTime();
                        dt_x1  = rpchit->getX();
                        dt_y1  = rpchit->getY();
                        dt_z1  = rpchit->getZ();
                        dt_col = rpchit->getCol()-1;
                        dt_row = rpchit->getRow()-1;

                    }
                    if(rpchit->getTrbnum()==1) {
                        dt_t2  = rpchit->getTime();
                        dt_x2  = rpchit->getX();
                        dt_y2  = rpchit->getY();
                        dt_z2  = rpchit->getZ();
                    }
                }
                h_dt_2 -> Fill(dt_t2 - dt_t1 - sqrt( pow((dt_x2-dt_x1),2)
                                                    +  pow((dt_y2-dt_y1),2)
                                                    +  pow((dt_z2-dt_z1),2))/299.792458) ;

                h_dt_cell_2 -> Fill(dt_col*10+dt_row,dt_t2 - dt_t1 - sqrt( pow((dt_x2-dt_x1),2)
                                                                          +  pow((dt_y2-dt_y1),2)
                                                                          +  pow((dt_z2-dt_z1),2))/299.792458);

            }

            // Efficiency estimation!!!!!!!!!!!!

            //h_eff[2];
            Int_t nh =hits->GetEntriesFast();

            h_n_q[0]->Fill(Q1,M1);
            h_n_q[1]->Fill(Q2,M2);
            h_n_q[2]->Fill(Q3,M3);

            // Here we have a problem with the M3, because is not very stable
            if(fabs(M1-M2)<5.+M2*0.3 && fabs(M2-M1)<5.+M1*0.3) {

                h_n_q_clean[0] -> Fill( Q1 , M1 );
                h_n_q_clean[1] -> Fill( Q2 , M2 );
                h_n_q_clean[2] -> Fill( Q3 , M3 );

                h_log10q_flux[0] -> Fill(timeEvt,log10(Q1));
                h_log10q_flux[1] -> Fill(timeEvt,log10(Q2));
                h_log10q_flux[2] -> Fill(timeEvt,log10(Q3));

                h_nhits_flux[0] -> Fill(timeEvt, M1);
                h_nhits_flux[1] -> Fill(timeEvt, M2);
                h_nhits_flux[2] -> Fill(timeEvt, M3);

            }

            //h_flux2[6][6];

            // Special for efficiency:

            Int_t colH1[2]={-1,-1};
            Int_t colH2[2]={-1,-1};
            Int_t colH3[2]={-1,-1};

            Int_t rowH1[2]={-1,-1};
            Int_t rowH2[2]={-1,-1};
            Int_t rowH3[2]={-1,-1};

            Int_t countH1 = 0;
            Int_t countH2 = 0;
            Int_t countH3 = 0;

            for(Int_t j=0;j<nrpchits;j++) {
                TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(j);
                if(rpchit) {

                    Int_t col = rpchit->getCol()-1;
                    Int_t row = rpchit->getRow()-1;
                    //casos.
                    // en M1 puedo rellenar directamente el histograma!
                    if(M1==1 && rpchit->getTrbnum()==0 ) {
                        h_cell_counts_n1[rpchit->getTrbnum()]->Fill(timeEvt,col*10+row);
                    }
                    if(M2==1 && rpchit->getTrbnum()==1 ) {
                        h_cell_counts_n1[rpchit->getTrbnum()]->Fill(timeEvt,col*10+row);
                    }
                    if(M3==1 && rpchit->getTrbnum()==2 ) {
                        h_cell_counts_n1[rpchit->getTrbnum()]->Fill(timeEvt,col*10+row);
                    }

                    // en caso de M=2 hay que ver.
                    // Que no sean contiguos!
                    // Habria que ver que hacer con las celdas ruidosas para este analisis y eliminarlas
                    // ya que distorsionan las cosas!!!
                    // HAY QUE CREAR LISTAS DE CELDAS OK.
                    // Como tabla? o Como histograma?

                    if(M1==2 && rpchit->getTrbnum()==0) {
                        colH1[countH1] = col;
                        rowH1[countH1] = row;
                        countH1++;
                    }
                    if(M2==2 && rpchit->getTrbnum()==1) {
                        colH2[countH2] = col;
                        rowH2[countH2] = row;
                        countH2++;
                    }
                    if(M3==2 && rpchit->getTrbnum()==2) {
                        colH3[countH3] = col;
                        rowH3[countH3] = row;
                        countH3++;
                    }
                }
            }

            if(M1==2) {
                if(fabs(colH1[0]-colH1[1])<=1 && fabs(rowH1[0]-rowH1[1])<=1) {
                    h_cell_counts_n2[0]->Fill(timeEvt,colH1[0]*10+rowH1[0]);
                    h_cell_counts_n2[0]->Fill(timeEvt,colH1[1]*10+rowH1[1]);
                }
            }
            if(M2==2) {
                if(fabs(colH2[0]-colH2[1])<=1 && fabs(rowH2[0]-rowH2[1])<=1) {
                    h_cell_counts_n2[1]->Fill(timeEvt,colH2[0]*10+rowH2[0]);
                    h_cell_counts_n2[1]->Fill(timeEvt,colH2[1]*10+rowH2[1]);
                }
            }
            if(M3==2) {
                if(fabs(colH3[0]-colH3[1])<=1 && fabs(rowH3[0]-rowH3[1])<=1) {
                    h_cell_counts_n2[2]->Fill(timeEvt,colH3[0]*10+rowH3[0]);
                    h_cell_counts_n2[2]->Fill(timeEvt,colH3[1]*10+rowH3[1]);
                }
            }

            Int_t binthetaeff = 0;
            if(M1 == M2 && M1==1 && ntracks==1 ) {

                TRpcSaeta* RpcSaeta2  = (TRpcSaeta*)RpcSaeta2Planes->At(0);
                if(!RpcSaeta2) {
                    cout<<"RpcSaeta2 not found, but it was there: WARNING"<<endl;
                    continue;
                }
                binthetaeff = floor(RpcSaeta2->getThetaDeg()/5.);
                //cout<<"test bin theta "<<binthetaeff<<endl;
                if( binthetaeff > 11 ) binthetaeff = 11;
                Int_t col, row;
                Float_t tref, tm;
                tref = -10000;
                Bool_t valid = kFALSE;
                Float_t x,y,z,xref,yref,zref;
                Float_t xref2,yref2,zref2;
                Float_t xteo, yteo;
                Int_t col1,col2,row1,row2;
                //cout<<"such event exists "<<endl;
                Int_t counter=0;
                for(Int_t j=0;j<nrpchits;j++) {
                    TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(j);
                    if(rpchit->getTrbnum()==0) {
                        tref = rpchit->getTime();
                        zref = rpchit->getZ();
                        xref = rpchit->getX();
                        yref = rpchit->getY();
                        col1 = rpchit->getCol()-1;
                        row1 = rpchit->getRow()-1;
                    }
                    if(rpchit->getTrbnum()==1) {
                        zref2 = rpchit->getZ();
                        xref2 = rpchit->getX();
                        yref2 = rpchit->getY();
                        col2 = rpchit->getCol()-1;
                        row2 = rpchit->getRow()-1;
                    }
                    if(rpchit->getTrbnum()==2) {
                        counter++;
                    }
                }
                if(col1==col2 && row1==row2) {
                    Bool_t det3True = 0;
                    for(Int_t j=0;j<nrpchits;j++) {
                        TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(j);
                        if(rpchit->getTrbnum()==2) {
                            if(rpchit->getCol()-1==col1 && rpchit->getRow()-1==row1 )
                                det3True = 1;
                        }
                    }

                    h_eff_nn[0] -> Fill(timeEvt);
                    if(det3True) {
                        h_eff_nn[1] -> Fill(timeEvt);
                        //h_eff_nn[1] -> Fill(10);
                        //h_eff_nn[0] -> Fill(10);
                    }
                }

                xteo = (xref-xref2)/(zref-zref2) * (1826-zref) + xref;
                yteo = (yref-yref2)/(zref-zref2) * (1826-zref) + yref;

                //if(col1!=col2 || row1!=row2) continue;
                //if(fabs(yteo)>500)continue;
                //if(fabs(xteo)>600)continue;

                h_eff[0]  -> Fill(timeEvt,xteo);

                //h_y_x_theta[0][binthetaeff] -> Fill(xteo,yteo);

                Bool_t once = kTRUE;
                //if(counter>1)continue;
                for(Int_t j=0;j<nrpchits;j++) {
                    TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(j);
                    if(rpchit->getTrbnum()==2) {
                        // Valid
                        // valid = kTRUE;
                        tm  = rpchit->getTime();
                        col = rpchit->getCol()-1;
                        row = rpchit->getRow()-1;

                        z = rpchit->getZ();
                        x = rpchit->getX();
                        y = rpchit->getY();

                        //cout<<"xteo "<<xteo<<" x "<<x<<" yteo "<<yteo<<" y "<<y<<endl;
                        if(once && fabs(xteo-x)<400. && fabs(yteo-y)<400.) {
                            //h_y_x_theta[1][binthetaeff] -> Fill(xteo,yteo);
                            //h_y_x_theta[2][binthetaeff] -> Fill(x,y);
                            h_eff[1] -> Fill(timeEvt,xteo);
                            //h_itse -> Fill(xteo,yteo);
                            once = kFALSE;
                        }
                    }
                }
                //if(valid)
            }

            // Loop for statistics.
            // This also has to be used in order to see the impact in the

            Float_t tracktime=0.;

            if(ntracks==1) {
                TRpcSaeta* RpcSaeta2  = (TRpcSaeta*)RpcSaeta2Planes->At(0);
                //tracktime = RpcSaeta2->getTime();
                Int_t ind0 = RpcSaeta2->getInd(0);
                if(ind0>360)cout<<RpcSaeta2Planes->GetEntriesFast()<<" ind "<<ind0<<endl;
                //ind1 = RpcSaeta2->getInd(1);
                TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(ind0);
                tracktime = rpchit->getTime();

            }

            Int_t cm0=0;
            Int_t cm1=0;

            for(Int_t j=0;j<nrpchits;j++) {
                TRpcHit* rpchit = (TRpcHit*)rpccalhits->At(j);
                Int_t col1,row1;
                if(rpchit) {
                    col1 = rpchit->getCol()-1;
                    row1 = rpchit->getRow()-1;
                    if(rpchit->getTrbnum()<3)
                        h_cell_counts[rpchit->getTrbnum()]->Fill(timeEvt,col1*10+row1);
                    if(ntracks==1) {
                        if(rpchit->getTrbnum()==0) {
                            if(fabs(tracktime-rpchit->getTime())<100.) cm0++;
                        }
                        if(rpchit->getTrbnum()==1) {
                            if(fabs(tracktime-rpchit->getTime())<100.) cm1++;
                        }
                    }
                }
            }

            Int_t eventCase = 5;
            // We need to store the used hits in order to avoid possible re-use.

            //if(M1==1 && M2==1 && ntracks==1) eventCase = 0;
            if(cm0==1 && cm1==1 && ntracks==1) eventCase = 0;
            else if(M1==2 && M2==2 && ntracks>=2) eventCase = 1;
            else if(M1==3 && M2==3 && ntracks>=3) eventCase = 2;
            else if(M1==4 && M2==4 && ntracks>=4) eventCase = 3;
            else if(M1>=5 && M2>=5 && ntracks>=5) eventCase = 4;
            else eventCase = 5;

            Bool_t dontFill = 0;

            if(eventCase>0 && eventCase<5) {

                vector <Int_t>usedhits1;
                vector <Int_t>usedhits2;

                for(Int_t tr=0;tr<ntracks;tr++) {
                    TRpcSaeta* RpcSaeta2 = (TRpcSaeta*)RpcSaeta2Planes->At(tr);
                    if(RpcSaeta2) {
                        if( std::find(usedhits1.begin(), usedhits1.end(), RpcSaeta2->getInd(0)) == usedhits1.end() ) {
                            // not found. Then push_back
                            usedhits1.push_back(RpcSaeta2->getInd(0));
                        }
                        if(std::find(usedhits2.begin(), usedhits2.end(), RpcSaeta2->getInd(1)) == usedhits2.end()) {
                            usedhits2.push_back(RpcSaeta2->getInd(1));
                        }
                    }
                }
                if(usedhits1.size()<(eventCase+1) ||
                   usedhits2.size()<(eventCase+1))
                {
                    //This is not a pure case!
                    //
                    dontFill = 1;
                    //continue;
                }
            }

            if(dontFill==0) {
                h_flux2[eventCase][thetaBin] -> Fill(timeEvt,phi);
            }

            EventNr++;

            // Flux of particles!
            if(ntracks3<1) continue;  // Skip events with less than 1 track in 3 planes
            if(thetaBin<0) continue;
            //fTheta_intervals[7]

            // Work with your histograms here!

            // If not in sync-> Continue;
            // Take correction from DAQ active to account for missing time in the bin.
            // Every second we must have an entry in daq active.

            //Casos M1=1 M2=1 M3=1 tracks=1
            //Casos M1=2 M2=2 M3=2 tracks=2
            //Casos M1=3 M2=3 M3=3 tracks=3
            //Casos M1=4 M2=4 M3=4 tracks=4
            //Casos M1=>5 M2=>5 M3=>5 tracks=5
            eventCase = 5;
            // We need to store the used hits in order to avoid possible re-use.

            if(M1==1 && M2==1 && M3==1 && ntracks3==1) eventCase = 0;
            else if(M1==2 && M2==2 && M3==2 && ntracks3>=2) eventCase = 1;
            else if(M1==3 && M2==3 && M3==3 && ntracks3>=3) eventCase = 2;
            else if(M1==4 && M2==4 && M3==4 && ntracks3>=4) eventCase = 3;
            else if(M1>=5 && M2>=5 && M3>=5 && ntracks3>=5) eventCase = 4;
            else eventCase = 5;

            if(eventCase>0 && eventCase<5) {

                vector <Int_t>usedhits1;
                vector <Int_t>usedhits2;
                vector <Int_t>usedhits3;

                for(Int_t tr=0;tr<ntracks3;tr++) {
                    TRpcSaeta* RpcSaeta3 = (TRpcSaeta*)RpcSaeta3Planes->At(tr);
                    if(RpcSaeta3) {
                        if( std::find(usedhits1.begin(), usedhits1.end(), RpcSaeta3->getInd(0)) == usedhits1.end() ) {
                            // not found. Then push_back
                            usedhits1.push_back(RpcSaeta3->getInd(0));
                        }
                        if(std::find(usedhits2.begin(), usedhits2.end(), RpcSaeta3->getInd(1)) == usedhits2.end()) {
                            usedhits2.push_back(RpcSaeta3->getInd(1));
                        }
                        if(std::find(usedhits3.begin(), usedhits3.end(), RpcSaeta3->getInd(2)) == usedhits3.end()) {
                            usedhits3.push_back(RpcSaeta3->getInd(2));
                        }
                    }
                }

                if(usedhits1.size()<(eventCase+1) ||
                   usedhits2.size()<(eventCase+1) ||
                   usedhits3.size()<(eventCase+1))
                {
                    //This is not a pure case!
                    continue;
                }
            }

            h_flux3[eventCase][thetaBin3] -> Fill(timeEvt,phi3);
            //h_daq_active;
            //h_daq_sync;

        }
        delete event;
        delete rawFinder;
        delete calFinder;
        delete trackFinder;
        return kTRUE;
    }
}

void doStaffCalibration(char* path,char* name) {
    TString fName(name);
    TString fPath(path);
    Unpacker unpack =  Unpacker();
    TString day(fName(15,fName.First(".")-15));
    cout<<"DAY "<<day<<endl;
    cout<<"PATH to files "<<fName<<endl;
    //unpack.setFileLookupPar("../pars/luptab.txt");
    unpack.setFileLookupPar("luptab2014_082_2015.txt");
    //unpack.setFileLookupPar("../pars/luptab_20160722.txt");
    //unpack.setFileLookupPar("../pars/luptab_20170900.txt");
    //unpack.setFileLookupPar("luptable_corr_20180423.txt");
    //unpack.setFileHitFinderPar("../pars/time_calPar.txt");
    //unpack.setFileHitFinderPar("../pars/time_calPar3planes.txt");
    unpack.setFileHitFinderPar("empty_cal_2016.txt");
//    unpack.setFileHitFinderPar("../specialDST/pars/"+day+"_CalPars.txt");
    //unpack.setFileHitFinderPar("../pars2/2017_day_255_CalPars.txt");
    //unpack.setFileHitFinderParOut("../2017DST/pars/"+day+"_CalPars.txt");
    // Tracking Teest Line
    unpack.setFileHitFinderParOut("../TrackingTest/pars/"+day+"_CalPars.txt");
    unpack.fillCalibration(fPath,fName,"../TrackingTest/qcalhistos/", day+"_qhistos.root",1000000,0);
    // Si la lista esta en un directorio superior
    //unpack.fillCalibration(fPath,"../"+fName,"../2018DST/qcalhistos/",day+"_qhistos.root",1000000,0);

    // El directorio con las listas esta en el mismo directorio
    //unpack.fillCalibration(fPath,fName,"../2017DST/qcalhistos/",day+"_qhistos.root",1000000,0);
    //unpack.fillCalibration("/media/Datos2TB/tragaldabas/data/done/","../"+fName,"../qcalhistos2/",day+"_qhistos.root",1000000,0);
}

void doStaffAnalysis(char* path,char* name){
    TString fName(name);
    TString fPath(path);
    Filler fill =  Filler();
    TString day(fName(15,fName.First(".")-15));
    cout<<"ana DAY "<<day<<endl;
    cout<<"ana PATH to files "<<fName<<endl;
    //fill.setFileLookupPar("../pars/luptab.txt");
    fill.setFileLookupPar("luptab2014_082_2015.txt");
    //fill.setFileLookupPar("../pars/luptab_20160722.txt");
    //fill.setFileLookupPar("../pars/luptab_20170900.txt");
    //fill.setFileLookupPar("luptable_corr_20180423.txt");
    //fill.setFileHitFinderPar("../2017DST/pars/"+day+"_CalPars.txt");
    // Tracking Test Lines
    fill.setFileHitFinderPar("../TrackingTest/pars/"+day+"_CalPars.txt");
    fill.fillHistograms(fPath,fName,"../TrackingTest/results/", day+"_result_histos.root",1000000,0);
    //fill.setFileHitFinderPar("/media/Datos2TB/korna/tragaldabas/soft2/cal_350_2016.txt");

    //fill.fillHistograms(fPath,"../"+fName,"../2018DST/results/",day+"_result_histos.root",1000000,0);
    //fill.fillHistograms(fPath,fName,"../2017DST/results/",day+"_result_histos.root",1000000,0);
    //fill.fillHistograms("/media/Datos2TB/tragaldabas/data/done/","../"+fName,"../specialDST/results/",day+"_result_histos.root",1000000,0);
}

int main(int argc, char* argv[] ) {
    cout<<"Starting list "<<argv[2]<<" data path: "<<argv[1]<<endl;
    doStaffCalibration(argv[1],argv[2]);
    doStaffAnalysis(argv[1],argv[2]);
    return 1;

}


