#include "gameoflife.h"

using namespace std;

GameOfLife::GameOfLife() {
    nrows = 30;
    ncols = 30;
    get_random_field();
}

void GameOfLife::change_field_size(size_t newRows, size_t newCols) {
    nrows = newRows;
    ncols = newCols;
}

void GameOfLife::import_state(const string filename) {
    ifstream myfile;
    string line;
    vector<vector<Cell>> field;
    myfile.open(filename);
    bool open = myfile.is_open();
    if (open)  {
        size_t row = 0;
        while (myfile >> line) {
            if (row < 2) {}
            else field.emplace_back(toCellVec(line, row-2));
            row ++;
        }
    }
    myfile.close();
    currentGeneration = field;
    nrows = field.size();
    ncols = field[0].size();
}

vector<Cell> GameOfLife::toCellVec(string line, size_t row) {
    vector<Cell> cellVec;
    for (size_t col = 0; col < line.size(); col++) {
        Cell newCell = Cell(row, col);
        assert(line[col] == 'o' || line[col] == '*');
        newCell.set_status(newCell.status_from_char(line[col]));
        cellVec.emplace_back(newCell);
    }
    return cellVec;
}

void GameOfLife::write_to_file(string outfile) {
    ofstream myOutfile;
    string output = current_to_string();
    myOutfile.open(outfile, ios::out);
    cout << "Saving state to " << outfile << endl;
    myOutfile << nrows << endl << ncols << endl << output;
    myOutfile.close();
}

void GameOfLife::get_random_field() {
    vector<vector<Cell>> randomField;
    for (size_t i=0; i< nrows; i++) {
        vector<Cell> lineVec;
        for (size_t j=0; j<ncols; j++) {
            int value = rand() % 2;
            lineVec.emplace_back(Cell(i, j, value));
        }
        randomField.emplace_back(lineVec);
    }
    this->currentGeneration = randomField;
}

string GameOfLife::current_to_string() {
    string matrixOut;
    for (size_t i=0; i<nrows; i++) {
        for (size_t j=0; j<ncols; j++) {
            Cell cell = currentGeneration[i][j];
            matrixOut += cell.status_to_char();
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
