#ifndef CELL_H
#define CELL_H
#include <vector>

class Cell
{
public:
    Cell(size_t i, size_t j);
    Cell(size_t i, size_t j, int value);

    size_t row;
    size_t col;

    int status;
    void set_status(int newStatus);

    size_t get_right(size_t ncols);
    size_t get_left(size_t ncols);
    size_t get_top(size_t nrows);
    size_t get_bottom(size_t nrows);

    void evolve(int aliveCount);
};

int operator+(Cell& lhs, Cell& rhs);
int operator+(int x, Cell& rhs);

#endif // CELL_H
