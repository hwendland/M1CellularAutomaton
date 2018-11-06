#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "cell.h"
#include <iostream>
#include <fstream>

using namespace std;

class GameOfLife
{

    Cell **get_dynamic_array(const pair<int, int> dimensions);
    void set_current(Cell **field);

    pair<int,int> get_dimensions(const string filename);

    string current_to_string();

    int count_living(Cell cell);


public:
    GameOfLife();

    void get_random_field(const pair <int, int> dimensions);
    void change_field_size(int nrows, int ncols);
    void import_state(const string filename);
    void write_to_file(string outfile);

    int nrows, ncols;
    Cell **currentGeneration;
    void print_current();

    void start_game();
    void evolve();
};

#endif // GAMEOFLIFE_H
