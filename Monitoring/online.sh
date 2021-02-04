#!/bin/bash

cd /media/Datos2TB/tragaldabas/data/Done/
file=`ls -t *hld | head -n 1`
cd $OLDPWD
echo
echo New file found!
echo
echo Analyzing file: $file
echo

cat > unpack.swap <<"EOF"
{
 Unpacker* u = new Unpacker("/media/Datos2TB/tragaldabas/data/done/","XXXXXXXXX","./",10000000,"luptab.txt","2017_day_263_CalPars.txt");
}
EOF

ORDE=`echo s/XXXXXXXXX/$file/g`

sed "$ORDE" unpack.swap > unpack.C
rm unpack.swap

root -l -q unpack.C

cat > drawHits.swap <<"EOF"
{
    gROOT->SetBatch(kTRUE);
    TFile *_file0 = TFile::Open("XXXXXXXXX.root.root");
    gStyle->SetOptStat(1000000001);
    TCanvas* can = new TCanvas("can","can",1100,700);
    can->Divide(3,2,0.01,0.01);
    can->cd(1);T->Draw("rpcraw.fRow-1:rpcraw.fCol-1>>T1(12,0,12,10,0,10)","rpcraw.fTrbnum==2","colz text");
    T1->SetTitle("XXXXXXXXX;column;row");can_1->SetLogz();
    T1->GetZaxis()->SetRangeUser(0,10000);
    can->cd(2);T->Draw("rpcraw.fRow-1:rpcraw.fCol-1>>T3(12,0,12,10,0,10)","rpcraw.fTrbnum==0","colz text");
    T3->SetTitle("XXXXXXXXX;column;row");can_2->SetLogz();
    T3->GetZaxis()->SetRangeUser(0,10000);
    can->cd(3);T->Draw("rpcraw.fRow-1:rpcraw.fCol-1>>T4(12,0,12,10,0,10)","rpcraw.fTrbnum==1","colz text");
    T4->SetTitle("XXXXXXXXX;column;row");can_3->SetLogz();
    T4->GetZaxis()->SetRangeUser(0,10000);
    can->cd(4);T->Draw("event.multH1>>mT1(120,0,120)");can_4->SetLogy();can_4->SetLogx();
    mT1->SetTitle("XXXXXXXXX;hit multiplicity;events");mT1->SetFillColor(5);
    //mT1->GetXaxis()->SetRangeUser(0.1,250);
    mT1->GetYaxis()->SetRangeUser(1,300000);
    can->cd(5);T->Draw("event.multH2>>mT3(120,0,120)");can_5->SetLogy();can_5->SetLogx();
    mT3->SetTitle("XXXXXXXXX;hit multiplicity;events");mT3->SetFillColor(5);
    //mT3->GetXaxis()->SetRangeUser(0.1,250);
    mT3->GetYaxis()->SetRangeUser(1,300000);
    can->cd(6);T->Draw("event.multH3>>mT4(200,0,200)");can_6->SetLogy();can_6->SetLogx();
    mT4->SetTitle("XXXXXXXXX;hit multiplicity;events");mT4->SetFillColor(5);
    //mT4->GetXaxis()->SetRangeUser(0.1,250);
    mT4->GetYaxis()->SetRangeUser(1,300000);
    can->SaveAs("png/YYMMDD/XXXXXXXXX.png");
    can->SaveAs("tmpShow.pdf");
    ofstream fs("png/YYMMDD/rate/XXXXXXXXX_cell_entries.dat");
    fs << "#T1" << endl;
    for(Int_t i=10;i>0;i--) { 
      for(Int_t j=1;j<13;j++) {
        fs << T1->GetBinContent(j,i) << "\t";
      }
      fs << endl;
    }
    fs << "#T3" << endl;
    for(Int_t i=10;i>0;i--) { 
      for(Int_t j=1;j<13;j++) {
        fs << T3->GetBinContent(j,i) << "\t";
      }
      fs << endl;
    }
    fs << "#T4" << endl;
    for(Int_t i=10;i>0;i--) { 
      for(Int_t j=1;j<13;j++) {
        fs << T4->GetBinContent(j,i) << "\t";
      }
      fs << endl;
    }
    fs.close();
    ofstream fs2("png/YYMMDD/rate/XXXXXXXXX_plane_mult.dat");
    fs2 << "#T1" << endl;
    for(Int_t i=1;i<120;i++) fs2 << mT1->GetBinContent(i) << "\t";
    fs2 << "\n#T3" << endl;
    for(Int_t i=1;i<120;i++) fs2 << mT3->GetBinContent(i) << "\t";
    fs2 << "\n#T4" << endl;
    for(Int_t i=1;i<200;i++) fs2 << mT4->GetBinContent(i) << "\t";
    fs2.close();
}
EOF

sed "$ORDE" drawHits.swap > drawHits_tmp.C
rm drawHits.swap

#DATE=`date +%d%B%Y`
#DATE=`date +%Y%m%d`
DATE=${file:2:5}

if ! [ -d  png/$DATE/ ];
then
mkdir -p png/$DATE/rate
fi
#ORDE2=`echo s/DDMMYY/$DATE/g`
ORDE2=`echo s/YYMMDD/$DATE/g`
sed "$ORDE2" drawHits_tmp.C > drawHits.C
rm drawHits_tmp.C

root -l -q drawHits.C

evince tmpShow.pdf &

rm $file.root.root

