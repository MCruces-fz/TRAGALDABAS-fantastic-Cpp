#!/bin/bash

FILENAME=$1

echo
echo Analyzing file: $FILENAME
echo

HLDDIR="/media/Datos2TB/tragaldabas/data/done/"
OUTDIR="/media/Datos4TB/tragaldabas/data/Nov2020_dst/root/"
LUPTAB="luptab.txt"
CALPARS="/media/Datos2TB/damian/tragaldabas/2020DST/pars/2020_day_290_CalPars.txt"

# cat > unpack.C <<EOF
root -l -q <<EOF
{
 Unpacker* u = new Unpacker("$HLDDIR", "$FILENAME", "$OUTDIR", 10000000, "$LUPTAB", "$CALPARS");
}
EOF

# ORDE=`echo s/XXXXXXXXX/$1/g`

# sed "$ORDE" unpack.swap > unpack.C
# rm unpack.swap

# root -l -q unpack.C
