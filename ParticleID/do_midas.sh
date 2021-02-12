#!/bin/bash

COMMAND=$1
FROMDATE=$2
TODATE=$3

# fppercebe dirs:
ROOTDIR="/home/mcruces/Documents/fptrucha_hits/root/"

# fptrucha dirs:
# ROOTDIR="/media/Datos4TB/people/mcruces/ICRCDST/unpacked/"

OUTNAME="OUT`date +"%y%j%H%M%S"`.csv"
WARNNAME="WARN`date +"%y%j%H%M%S"`.txt"

echo
echo "`date`"
echo
echo "Header of $OUTNAME:"
echo "RUNID, EVTNB, ID, P_ID, chi2, HITST1, HITST3, HITST4"
echo
echo "    RUNID: Identification od the run."
echo "    EVTNB: Event number."
echo "    ID: Particle identification by MIDAS algorithm."
echo "    P_ID: Probability of successful ID."
echo "    chi2: Chi squared."
echo "    HITST#: Hits in each plane in this event."

function show_help() {
    echo "To use the run command, arguments [FROM] and [TO] must be:"
    echo "    Integers"
    echo "    Dates with the format YYDOYHHMMSS"
    echo "        YY: Two digits year"
    echo "        DOY: Three digits Day Of the Year"
    echo "        HHMMSS: Time HH:MM:SS"
    echo "They can have the desired length, but starting allways"
    echo "with the year (YY) and followed by the day of the year (DOY) "
    echo
    echo "To remove all warnings, use rm-warn as last argument."
}

function MIDAS() {
    FULLNAME=$1
    
    # echo Analyzing file: `basename $FULLNAME`
    
    root -l <<EOF >> $OUTNAME 2>> $WARNNAME 
{
.L ParticleID3Plane.C
Saetas3Planes("$FULLNAME");
}
EOF
}

function run_all() {
    for a in `find $ROOTDIR -maxdepth 1 -type f -name "*.hld.root.root" -print`; 
    do 
        MIDAS $a
    done
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
        for a in `find $ROOTDIR -maxdepth 1 -type f -name "tr$date*.hld.root.root" -print`; 
        do 
            MIDAS $a
        done
    done
}

case $COMMAND in
run)       run         ;;
run-all)   run_all     ;;
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
    echo "    run-all "
    echo "    --help    <- Show more extended help."
    echo "         "
    ;;
esac

if [[ $1 == "rm-warn"  || $2 == "rm-warn" || $4 == "rm-warn" ]]; then
    rm WARN*
fi
