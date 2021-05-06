#!/bin/bash

COMMAND=$1
FROMDATE=$2
TODATE=$3

# HLDDIR="/home/mcruces/Documents/fptrucha_hits/root/"
# HLDDIR="/home/mcruces/Documents/fptrucha_hits/test01/"
# OUTDIR="/home/mcruces/Documents/fptrucha_hits/test01/"
# LUPTAB="../luptabs/luptable_20201013.txt"
# PARSDIR="../CalPars/"

HLDDIR="/media/Datos2TB/tragaldabas/data/done/"
# HLDDIR="/media/Datos4TB/people/mcruces/SELFTRIGGER/hlds/"
# OUTDIR="/media/Datos4TB/people/mcruces/TEST/unpacked/"
OUTDIR="/media/Datos4TB/people/mcruces/APR/"
# LUPTAB="/media/Datos2TB/tragaldabas/luptab/luptable_corr_20180423.txt"
LUPTAB="/media/Datos2TB/tragaldabas/luptab/luptable_20210415.txt"
# Tomarlos de korna: /media/Datos2TB/korna/tragaldabas/pars(2)/*
PARSDIR="/media/Datos2TB/damian/tragaldabas/2021DST/pars/" # Damian
# PARSDIR="/media/Datos2TB/damian/tragaldabas/2020DST/pars/" # Damian

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

function do_unpack() {
    FILENAME=$1

    # Read date from filename
    YY=${FILENAME:2:2}
    DOY=${FILENAME:4:3}
    # Force date
    YY=21
    DOY=109

    PARSFILE="$PARSDIR/20${YY}_day_${DOY}_CalPars.txt"

    if [ ! -f $PARSFILE ]; then
        echo "File $PARSFILE not found!"
        return 1
    fi
    
    echo Analyzing file: $FILENAME
    
    # cat > unpack.C <<EOF
    root -l  <<EOF
{
Unpacker* u = new Unpacker("$HLDDIR", "$FILENAME", "$OUTDIR", 10000000, "$LUPTAB", "$PARSFILE");
}
EOF
    # root -l -q unpack.C
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
        for a in `find $HLDDIR -maxdepth 1 -type f -name ??$date* -print`; 
        do 
            do_unpack `basename $a`
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

