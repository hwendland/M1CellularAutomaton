#ifndef CELL_H
#define CELL_H
#include <vector>
#include <iostream>

using namespace std;

class Cell
{
public:
    /*!
     * @brief Concstructors. Instances represent fields of the Cellular Automaton/field for the Game of Life
     */
    Cell() {}
    Cell(int i, int j);
    Cell(int i, int j, int value);

    // the cell's coordinates on the 2D field
    int row;
    int col;

    int status; // 0 = o = dead; 1 = * = living
    /*!
     * @brief Change the Cell's status
     * @param value: int status (0 or 1) for direct access
     * @param newStatus: char status (* or o) will be converted to int
     */
    void set_status(int value);
    void set_status(char newStatus);

    /*!
     * @brief Conversion between integer and character status for file import/export and printing
     */
    static int status_from_char(char x);
    char status_to_char();

    /*!
     * @brief Get neighboring row or column index (Moore neighborhood) on Game of Life field
     * @param ncols: number of columns on the field
     * @param nrows: number of rows on the field
     * @returns row or column index of neighbor
     */
    int get_right(int ncols);
    int get_left(int ncols);
    int get_top(int nrows);
    int get_bottom(int nrows);

    /*!
     * @brief Compute next generation cell status based on number of living neighbors
     * @param aliveCount: number of living neighbor cells on the field
     * @see GameOfLife::count_living
     */
    void evolve(int aliveCount);
};

/*!
 * @brief Convenience functions for counting living cells
 */
int operator+(Cell& lhs, Cell& rhs);
int operator+(int x, Cell& rhs);

#endif // CELL_H
