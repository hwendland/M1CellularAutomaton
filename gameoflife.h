#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "cell.h"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class GameOfLife
{  
    /*!
     * @brief Allocates space for nextGeneration and currentGeneration
     * @param dimensions: number of rows and columns
     * @returns pointer to array of Cells
     */
    Cell **get_dynamic_array(const pair<int, int> dimensions);

    /*!
     * @brief Copies nextGeneration to currentGeneration after evolution has finished
     */
    void set_current();

    /*!
     * @brief Extracts field dimensions from first to lines of import file
     * @param filename: input file that contains the state to import
     * @returns number of rows and columns
     */
    pair<int,int> get_dimensions(const string filename);

    /*!
     * @brief Convert field to string for printing/writing to file
     * @returns String representation of field in rows and columns (Matrix)
     */
    string current_to_string();

    /*!
     * @brief Count living neighbors of a particular cell on the field
     * @param cell: the cell of interest
     * @returns number of living neighbors
     */
    int count_living(Cell cell);

    Cell **nextGeneration; // container for evolved cells

public:
    // Constructor
    GameOfLife();

    bool is_running;
    int nrows, ncols; // field dimensions
    Cell **currentGeneration; // container for current state

    /*!
     * @brief Fill currentGeneration with random cells
     */
    void get_random_field();

    /*!
     * @brief Change nrows and ncols and re-allocate space for currentGeneration and nextGeneration
     */
    void change_dimensions(const pair<int, int> dimensions);

    /*!
     * @brief State import and export
     * @param filename: file that contains state to import
     * @param outfile: file to export current state to
     */
    void import_state(const string filename);
    void write_to_file(string outfile);

    /*!
     * @brief Print string representation of field to console
     * @see GameOfLife::current_to_string()
     */
    void print_current();

    /*!
     * @brief Generate the next generation of the field by evolving each cell
     * @see Cell::evolve()
     */
    void evolve();

    /*!
     * @brief Utility function to safely convert user input to integer
     */
    static int to_stoi(string input);
};

#endif // GAMEOFLIFE_H
