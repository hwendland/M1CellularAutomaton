#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "cell.h"
#include <iostream>
#include <fstream>

using namespace std;

class GameOfLife
{

    string current_to_string();

    vector<Cell> toCellVec(string line, size_t row);
    int count_living(Cell cell);


public:
    GameOfLife();

    void get_random_field();
    void change_field_size(size_t nrows, size_t ncols);
    void import_state(const string filename);
    void write_to_file(string outfile);

    size_t nrows, ncols;
    vector<vector<Cell>> currentGeneration;
    void print_current();

    void start_game();
    void evolve();
};

#endif // GAMEOFLIFE_H
