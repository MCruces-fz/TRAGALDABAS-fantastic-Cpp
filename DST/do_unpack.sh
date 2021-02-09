#!/bin/bash

echo
echo Analyzing file: $1
echo

HLDDIR="/media/Datos2TB/tragaldabas/data/done/"
OUTDIR="/media/Datos4TB/tragaldabas/data/Nov2020_dst/root/"

cat > unpack.swap <<"EOF"
{
 Unpacker* u = new Unpacker($HLDDIR, "XXXXXXXXX", $OUTDIR, 10000000, "luptab.txt","/media/Datos2TB/damian/tragaldabas/2020DST/pars/2020_day_290_CalPars.txt");
}
EOF

ORDE=`echo s/XXXXXXXXX/$1/g`

sed "$ORDE" unpack.swap > unpack.C
rm unpack.swap

root -l -q unpack.C
