#ifndef BADCELLS_H
#define BADCELLS_H


#include <list>

#include "../utils/constants.h"
#include "../utils/csv.h"

// using namespace std;

struct ReturnBC {
    /*
     *   This is the definition of the
     * structure of the ReadBadCells
     * function return.
     */

    Int_t T1 [20] = {[0 ... 19] = -1};
    Int_t T3 [20] = {[0 ... 19] = -1};
    Int_t T4 [20] = {[0 ... 19] = -1};
};

ReturnBC read_bad_cells(string badCellsFile) {

    // Bad Cells:
    ReturnBC bc;

    io::CSVReader<3> in(badCellsFile);
    in.read_header(io::ignore_extra_column, "T1", "T3", "T4");
    Int_t bc1, bc3, bc4;
    Int_t iter = 0;
    while(in.read_row(bc1, bc3, bc4)){
        bc.T1[iter] = bc1;
        bc.T3[iter] = bc3;
        bc.T4[iter] = bc4;

        iter++;
    }

    return bc;
}


list<Int_t> isBadCell(Int_t cell, int k) {

    ReturnBC badCells= read_bad_cells(c_bc_dir + "bad_cells_20270.csv");
    list<Int_t> indK;

    for (int c = 0; c < 20; c++) {
        if (cell == badCells.T1[c]) {
            indK.push_back(k);
            // indK.push_back(k);
            if (silly_prints) cout << "Cell " << cell << " is wrong, k index: " << k << endl;
        }
    }
    return indK;
}

#endif
