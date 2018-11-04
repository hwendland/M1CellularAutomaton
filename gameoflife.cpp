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
        vector<Cell> lineVec;
        for (size_t j=0; j<ncols; j++) {
            int value = rand() % 2;
            lineVec.emplace_back(Cell(i, j, value));
        }
        randomField.emplace_back(lineVec);
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
    cout << current_to_string() << endl;
}

int GameOfLife::count_living(Cell cell) {
    size_t right = cell.get_right(this->ncols);
    size_t left = cell.get_left(this->ncols);
    size_t top = cell.get_top(this->nrows);
    size_t bottom = cell.get_bottom(this->nrows);
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
    vector<vector<Cell>> nextGeneration;
    for (size_t i=0; i< nrows; i++) {
        vector<Cell> lineVec;
        for (size_t j=0; j<ncols; j++) {
            Cell currentCell = currentGeneration[i][j];
            int aliveCount = count_living(currentCell);
            currentCell.evolve(aliveCount);
            lineVec.emplace_back(currentCell);
        }
        nextGeneration.emplace_back(lineVec);
    }
    currentGeneration = nextGeneration;
}
