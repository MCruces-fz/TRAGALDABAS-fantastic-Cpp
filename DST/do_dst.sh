#!/bin/bash

COMMAND=$1
FROMDATE=$2
TODATE=$3

# HLDDIR="/media/Datos2TB/tragaldabas/data/done/alberto/T01T02T03/20150107/done/"
# HLDDIR="/home/mcruces/Documents/fptrucha_hits/root/"
HLDDIR="/media/Datos2TB/tragaldabas/data/done/"


function do_unpack() {
    
    FILENAME=$1
    
    echo
    echo Analyzing file: $FILENAME
    echo
    
    OUTDIR="/media/Datos4TB/tragaldabas/data/Nov2020_dst/root/"
    LUPTAB="luptab.txt"
    CALPARS="/media/Datos2TB/damian/tragaldabas/2020DST/pars/2020_day_290_CalPars.txt"
    
    # cat > unpack.C <<EOF
    root -l -q <<EOF
    {
     Unpacker* u = new Unpacker("$HLDDIR", "$FILENAME", "$OUTDIR", 10000000, "$LUPTAB", "$CALPARS");
    }
EOF

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
        for a in `find $HLDDIR -type f -name tr$date* -print`; 
        do 
            do_unpack() `basename $a`
            # ./do_unpack.sh `basename $a`;
        done
    done
}

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

