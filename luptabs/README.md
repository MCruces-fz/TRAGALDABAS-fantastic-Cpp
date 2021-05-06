# Lookup Tables

Data structure to save links between cell positions and hardware inputs. It is used to substitute the unpacking computation routine with a simple indexing of values. We have several luptabs (lookup tables), each of them for a period of time determined by the name.


## Lookup table structure:

There is a table for each active TRB:

```
LUPTABLE
<trb_id>  <trb_height>
1   1   1   1   7   5    63     60.5
2   1   2   2   8   5    189    60.5
3   1   3   3   9   5    315    60.5
4   1   4   4   10  5    441    60.5
5   1   5   5   11  5    567    60.5
6   1   6   6   12  5    693    60.5
7   1   7   7   7   4    63     181.5
8   1   8   8   8   4    189    181.5
9   1   9   9   9   4    315    181.5 
.   .   .   .   .   .    .      .
.   .   .   .   .   .    .      .
.   .   .   .   .   .    .      .
.   .   .   .   .   .    .      .
121 4   25  25  1   5   -693    60.5
122 4   26  26  2   5   -567    60.5
123 4   27  27  3   5   -441    60.5
124 4   28  28  4   5   -315    60.5
125 4   29  29  5   5   -183    60.5
126 4   30  30  6   5   -63     60.5
```

where `<trb_id>` is the identification number for each TRB and `<trb_height>` the height in mm measured from the floor:
 TRB ID  | Height / mm |  Plane name                                
:-------:|:-----------:|:-----------:
   888   |    1826.0   |     T1
   899   |    1304.0   |     T2
   837   |     924.0   |     T3
   871   |      87.0   |     T4


Each column of the table, in the same order, is:
- Channel in TRB [1, 126]
- Motherboard ID [1, 4]
- Motherboard Channel [1, 32]
- Cell number in motherboard [1, 30]
- Column number [1, 12]
- Row number [1, 10]
- X coordinate (The center of the cell)
- Y coordinate (The center of the cell)

The origin for (x, y) coordinates is in the middle of the TRB. The origin for de coordinates (col, row) starts in motherboard number 3.
