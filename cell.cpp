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

void Cell::set_status(char newStatus) {
    return set_status(status_from_char(newStatus));
}

int Cell::status_from_char(const char x) {
    switch (x) {
        case 'o': return 0;
        case '*': return 1;
        default: {
            cout << "Invalid. Using default value of o.\n";
            return 0;
         }
    }
}

char Cell::status_to_char() {
    switch(status) {
        case 0: return 'o';
        case 1: return '*';
        default: return 'o';
    }
}

size_t Cell::get_right(size_t ncols) {
    if (col == ncols-1) return 0;
    else return col + 1;
}

size_t Cell::get_left(size_t ncols) {
    if (col == 0) return ncols - 1;
    else return col - 1;
}

size_t Cell::get_top(size_t nrows) {
    if (row == 0) return nrows - 1;
    else return row - 1;
}

size_t Cell::get_bottom(size_t nrows) {
    if (row == nrows-1) return 0;
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

