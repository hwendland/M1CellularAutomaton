#ifndef CELL_H
#define CELL_H
#include <vector>
#include <iostream>

using namespace std;

class Cell
{
public:
    Cell() {}
    Cell(int i, int j);
    Cell(int i, int j, int value);

    int row;
    int col;

    int status;
    void set_status(int value);
    void set_status(char newStatus);
    int status_from_char(char x);
    char status_to_char();

    int get_right(int ncols);
    int get_left(int ncols);
    int get_top(int nrows);
    int get_bottom(int nrows);

    void evolve(int aliveCount);
};

int operator+(Cell& lhs, Cell& rhs);
int operator+(int x, Cell& rhs);

#endif // CELL_H
