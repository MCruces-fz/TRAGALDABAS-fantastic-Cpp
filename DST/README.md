# How To do a DST

Create softlinks (ln) in:
    - luptab.txt:
    - CalPars.txt:
to the current used files.

Then be sure the directories in *do_unpack.sh* are correct, and execute
```bash
./do_dst.sh run [FROM] [TO]
```
for example
```bash
./do_dst.sh run 20092 20121
```
to unpack from April 1st to April 31st of 2020

