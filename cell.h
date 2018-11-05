#ifndef CELL_H
#define CELL_H
#include <vector>
#include <iostream>

using namespace std;

class Cell
{
public:
    Cell(size_t i, size_t j);
    Cell(size_t i, size_t j, int value);

    size_t row;
    size_t col;

    int status;
    void set_status(int value);
    void set_status(char newStatus);
    int status_from_char(char x);
    char status_to_char();

    size_t get_right(size_t ncols);
    size_t get_left(size_t ncols);
    size_t get_top(size_t nrows);
    size_t get_bottom(size_t nrows);

    void evolve(int aliveCount);
};

int operator+(Cell& lhs, Cell& rhs);
int operator+(int x, Cell& rhs);

#endif // CELL_H
