#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "cell.h"
#include <iostream>

using namespace std;

class GameOfLife
{
    size_t nrows, ncols;

    vector<vector<Cell>> currentGeneration;

    vector<vector<Cell>> get_random_field();
    int count_living(Cell cell);

public:
    GameOfLife();

    void change_field_size(size_t nrows, size_t ncols);

    string current_to_string();
    void print_current();

    void start_game();
    void evolve();
};

#endif // GAMEOFLIFE_H
