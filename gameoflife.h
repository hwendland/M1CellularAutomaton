#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "cell.h"
#include <iostream>
#include <fstream>

using namespace std;

class GameOfLife
{

    Cell **get_dynamic_array(const pair<int, int> dimensions);

    Cell **nextGeneration;
    void set_current();

    pair<int,int> get_dimensions(const string filename);
    string current_to_string();

    int count_living(Cell cell);

public:
    GameOfLife();

    void get_random_field();
    void change_dimensions(const pair<int, int> dimensions);
    void import_state(const string filename);
    void write_to_file(string outfile);

    int nrows, ncols;
    Cell **currentGeneration;
    void print_current();

    void start_game();
    void evolve();
};

#endif // GAMEOFLIFE_H
