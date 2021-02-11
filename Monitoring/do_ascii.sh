#!/bin/bash

COMMAND=$1
FROMDATE=$2
TODATE=$3

# fptrucha dirs
HLDDIR="/media/Datos2TB/tragaldabas/data/done/"
OUTROOT="/media/Datos4TB/people/mcruces/PNGDST/"
OUTPNG="/media/Datos4TB/tragaldabas/data/monitor/"

# fptrucha files
LUPTAB="/media/Datos2TB/tragaldabas/luptab/luptable_corr_20180423.txt"
CALPARS="/media/Datos2TB/mcruces/tragaldabas/2020DST/pars/2020_day_092_CalPars.txt"

function show_help() {
    echo "To use the run command, arguments [FROM] and [TO] must be:"
    echo "    Integers"
    echo "    Dates with the format YYDOYHHMMSS"
    echo "        YY: Two digits year"
    echo "        DOY: Three digits Day Of the Year"
    echo "        HHMMSS: Time HH:MM:SS"
    echo "They can have the desired length, but starting allways"
    echo "with the year (YY) and followed by the day of the year (DOY) "
}

function do_root() {
    FILENAME=$1
    
    echo Analyzing file: $FILENAME
    
    root -l <<EOF
{
Unpacker* u = new Unpacker("$HLDDIR", "$FILENAME", "$OUTROOT", 10000000, "$LUPTAB", "$CALPARS");
}
EOF

    YYDOY=${FILENAME:2:5}

    # full paths to files
    YYDOYPATH="$OUTPNG/png/$YYDOY/"

    if ! [ -d  $YYDOYPATH ]; then
        mkdir -p $YYDOYPATH/rate/
    fi

    root -l <<EOF
{
    gROOT->SetBatch(kTRUE);
    TFile *_file0 = TFile::Open("$OUTROOT${FILENAME}.root.root");
    gStyle->SetOptStat(1000000001);
    TCanvas* can = new TCanvas("can","can",1100,700);
    can->Divide(3,2,0.01,0.01);
    can->cd(1);T->Draw("rpcraw.fRow-1:rpcraw.fCol-1>>T1(12,0,12,10,0,10)","rpcraw.fTrbnum==2","colz text");
    T1->SetTitle("$FILENAME;column;row");can_1->SetLogz();
    T1->GetZaxis()->SetRangeUser(0,10000);
    can->cd(2);T->Draw("rpcraw.fRow-1:rpcraw.fCol-1>>T3(12,0,12,10,0,10)","rpcraw.fTrbnum==0","colz text");
    T3->SetTitle("$FILENAME;column;row");can_2->SetLogz();
    T3->GetZaxis()->SetRangeUser(0,10000);
    can->cd(3);T->Draw("rpcraw.fRow-1:rpcraw.fCol-1>>T4(12,0,12,10,0,10)","rpcraw.fTrbnum==1","colz text");
    T4->SetTitle("$FILENAME;column;row");can_3->SetLogz();
    T4->GetZaxis()->SetRangeUser(0,10000);
    can->cd(4);T->Draw("event.multH1>>mT1(120,0,120)");can_4->SetLogy();can_4->SetLogx();
    mT1->SetTitle("$FILENAME;hit multiplicity;events");mT1->SetFillColor(5);
    //mT1->GetXaxis()->SetRangeUser(0.1,250);
    mT1->GetYaxis()->SetRangeUser(1,300000);
    can->cd(5);T->Draw("event.multH2>>mT3(120,0,120)");can_5->SetLogy();can_5->SetLogx();
    mT3->SetTitle("$FILENAME;hit multiplicity;events");mT3->SetFillColor(5);
    //mT3->GetXaxis()->SetRangeUser(0.1,250);
    mT3->GetYaxis()->SetRangeUser(1,300000);
    can->cd(6);T->Draw("event.multH3>>mT4(200,0,200)");can_6->SetLogy();can_6->SetLogx();
    mT4->SetTitle("$FILENAME;hit multiplicity;events");mT4->SetFillColor(5);
    //mT4->GetXaxis()->SetRangeUser(0.1,250);
    mT4->GetYaxis()->SetRangeUser(1,300000);
    can->SaveAs("$YYDOYPATH/${FILENAME}.png");
    // can->SaveAs("tmpShow.pdf");
    ofstream fs("$YYDOYPATH/rate/${FILENAME}_cell_entries.dat");
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
  ofstream fs2("$YYDOYPATH/rate/${FILENAME}_plane_mult.dat");
  fs2 << "#T1" << endl;
  for(Int_t i=1;i<120;i++) fs2 << mT1->GetBinContent(i) << "\t";
  fs2 << "\n#T3" << endl;
  for(Int_t i=1;i<120;i++) fs2 << mT3->GetBinContent(i) << "\t";
  fs2 << "\n#T4" << endl;
  for(Int_t i=1;i<200;i++) fs2 << mT4->GetBinContent(i) << "\t";
  fs2.close();
  }
EOF

    # evince tmpShow.pdf &

    rm $OUTROOT/${FILENAME}.root.root

}

function run() {

    re='^[0-9]+$'
    if ! [[ $FROMDATE =~ $re ]] ; then
        echo "Error: [FROM] is not a number" >&2
        exit 1

    elif ! [[ $TODATE =~ $re ]] ; then
        echo "Error: [TO] is not a number" >&2
        exit 1

    elif (( $FROMDATE > $TODATE )); then
        echo "Please: [FROM] < [TO]"
        exit 1
    fi

    for (( date=$FROMDATE; date<=$TODATE; date++))
    do
        for a in `find $HLDDIR -maxdepth 1 -type f -name tr$date* -print`; 
        do 
            do_root `basename $a`
        done
    done
}

case $COMMAND in
run)       run         ;;
--help)    show_help   ;;

*)
    if [[ $COMMAND == "" ]]; then
        echo "At least one argument is needed"
    else
        echo "Unrecognized command: ${COMMAND}"
    fi

    echo ""
    echo "Usage:"
    echo "$0 [COMMAND]" 
    echo ""
    echo "COMMAND:"
    echo "    run [FROM] [TO]"
    echo "    --help    <- Show more extended help."
    echo "         "
    ;;
esac

