#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "cell.h"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class GameOfLife
{  
    Cell **get_dynamic_array(const pair<int, int> dimensions);

    // nextGeneration holds new cell status until evolution has finished
    // and is then copied back into currentGeneration
    Cell **nextGeneration;
    void set_current();

    // extract field dimensions from first two lines of an import file
    pair<int,int> get_dimensions(const string filename);

    // convert field to string for printing/writing to file
    string current_to_string();

    // count living neighbors of a particular cell on the field
    int count_living(Cell cell);

public:
    // Constructor
    GameOfLife();

    bool is_running;

    void get_random_field();
    void change_dimensions(const pair<int, int> dimensions);
    // File import and export
    void import_state(const string filename);
    void write_to_file(string outfile);

    int nrows, ncols; // field dimensions
    Cell **currentGeneration;
    void print_current();

    void evolve(); // Generate the next generation (1 step)

    // Utility function to safely convert user input to integer
    static int to_stoi(string input);
};

#endif // GAMEOFLIFE_H
