#include "gameoflife.h"

using namespace std;

GameOfLife::GameOfLife() {
    nrows = 30;
    ncols = 30;
}

void GameOfLife::change_field_size(size_t newRows, size_t newCols) {
    ncols = newRows;
    nrows = newCols;
}

void GameOfLife::start_game() {
    if (!currentGeneration.size()) {
        currentGeneration = get_random_field();
    }
};

vector<vector<Cell>> GameOfLife::get_random_field() {
    vector<vector<Cell>> randomField;
    for (size_t i=0; i< nrows; i++) {
        for (size_t j=0; j<ncols; j++) {
            int value = rand() % 2;
            randomField[i][j] = Cell(i, j, value);
        }
    }
    return randomField;
}

string GameOfLife::current_to_string() {
    string matrixOut;
    for (size_t i=0; i<nrows; i++) {
        for (size_t j=0; j<ncols; j++) {
            Cell cell = currentGeneration[i][j];
            matrixOut.append(to_string(cell.status) + ' ');
        }
        matrixOut.append("\n");
    }
    return matrixOut;
};

void GameOfLife::print_current() {
    cout << current_to_string();
}

int GameOfLife::count_living(Cell cell) {
    size_t right = cell.get_right(ncols);
    size_t left = cell.get_left(ncols);
    size_t top = cell.get_top(nrows);
    size_t bottom = cell.get_bottom(nrows);
    int aliveCount =
        currentGeneration[top][left] +
        currentGeneration[top][cell.col] +
        currentGeneration[top][right] +
        currentGeneration[cell.row][left] +
        currentGeneration[cell.row][right] +
        currentGeneration[bottom][left] +
        currentGeneration[bottom][cell.col] +
        currentGeneration[bottom][right];
    return aliveCount;
}

void GameOfLife::evolve() {
    print_current();
    for (size_t i=0; i< nrows; i++) {
        for (size_t j=0; j<ncols; j++) {
            Cell currentCell = currentGeneration[i][j];
            int aliveCount = count_living(currentCell);
            currentCell.evolve(aliveCount);
            nextGeneration[i][j] = currentCell;
        }
    }
    copy_next_to_current();
    print_current();
}

void GameOfLife::copy_next_to_current() {
    for (size_t i=0; i< nrows; i++) {
        for (size_t j=0; j<ncols; j++) {
            currentGeneration[i][j] = nextGeneration[i][j];
        }
    }
}
