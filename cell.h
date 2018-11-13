#ifndef CELL_H
#define CELL_H
#include <vector>
#include <iostream>

using namespace std;

// Instances represent fields of the Cellular Automaton/Field for the Game of Life
class Cell
{
public:
    // Constructors
    Cell() {}
    Cell(int i, int j);
    Cell(int i, int j, int value);

    // the cell's coordinates on the 2D field
    int row;
    int col;

    int status; // 0 = o = dead; 1 = * = living
    void set_status(int value);
    void set_status(char newStatus);
    // Conversion between integer and character status for file import/export and printing
    static int status_from_char(char x);
    char status_to_char();

    // Get neighboring indices (1D) for Moore neighborhood
    int get_right(int ncols);
    int get_left(int ncols);
    int get_top(int nrows);
    int get_bottom(int nrows);

    // Next generation cell status based on number of living neighbours
    void evolve(int aliveCount);
};

// Adding two cells is equivalent to adding their (integer) status
// Simplifies counting of living cells in a neighborhood
int operator+(Cell& lhs, Cell& rhs);
int operator+(int x, Cell& rhs);

#endif // CELL_H
