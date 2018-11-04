#include "cell.h"

Cell::Cell(size_t i, size_t j) {
    row = i;
    col = j;
}

Cell::Cell(size_t i, size_t j, int value)
{
    row = i;
    col = j;
    status = value;
}

void Cell::set_status(int value) {
    status = value;
}

size_t Cell::get_right(size_t ncols) {
    if (col == ncols) return 0;
    else return col + 1;
}

size_t Cell::get_left(size_t ncols) {
    if (col == 0) return ncols;
    else return col - 1;
}

size_t Cell::get_top(size_t nrows) {
    if (row == 0) return nrows;
    else return row - 1;
}

size_t Cell::get_bottom(size_t nrows) {
    if (row == nrows) return 0;
    else return row + 1;
}

void Cell::evolve(int aliveCount) {
    switch (status) {
        case 0: if (aliveCount == 3) set_status(1); break;
        case 1: if (aliveCount < 2 || aliveCount > 3) set_status(0); break;
    }
}

int operator+(Cell& lhs, Cell& rhs) {
    return lhs.status + rhs.status;
}

int operator+(int x, Cell& rhs) {
    return x + rhs.status;
}

