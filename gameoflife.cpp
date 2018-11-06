#include "gameoflife.h"

using namespace std;

GameOfLife::GameOfLife() {
    nrows = 30;
    ncols = 30;
    currentGeneration = get_dynamic_array({nrows, ncols});
    get_random_field({nrows, ncols});
}

void GameOfLife::change_field_size(int newRows, int newCols) {
    nrows = newRows;
    ncols = newCols;
}

pair<int,int> GameOfLife::get_dimensions(const string filename) {
    ifstream myfile;
    pair<int, int> dimensions = {0,0};
    myfile.open(filename);
    if (myfile.is_open()) {
        string line;
        int i = 0;
        while (myfile >> line && i < 2) {
            if (i == 0) dimensions.first = stoi(line);
            else if (i == 1) dimensions.second = stoi(line);
            i++;
        }
    }
    return dimensions;
}

Cell **GameOfLife::get_dynamic_array(const pair<int, int> dimensions){
    Cell **dynArray;
    dynArray = new Cell*[dimensions.first];
    for (int i=0; i<dimensions.first; i++) {
        dynArray[i] = new Cell[dimensions.second];
    }
    return dynArray;
}

void GameOfLife::set_current(Cell **field) {
    for (int i=0; i<nrows; i++) {
        for (int j=0; j<ncols; j++) {
            currentGeneration[i][j] = field[i][j];
        }
    }
    delete field;
}

void GameOfLife::import_state(const string filename) {
    const pair<int, int> dimensions = get_dimensions(filename);
    ifstream myfile;
    string line;
    Cell **field = get_dynamic_array(dimensions);
    myfile.open(filename);
    if (myfile.is_open())  {
        int row = 0;
        while (myfile >> line) {
            if (row < 2) {}
            else {
                for (int col = 0; col < dimensions.second; col++) {
                    const size_t pos = static_cast<size_t>(col);
                    if (line[pos] == 'o' || line[pos] == '*') {
                        field[row-2][col] = Cell(row, col);
                        field[row-2][col].set_status(field[row-2][col].status_from_char(line[pos]));
                    } else {
                        field[row-2][col] = Cell(row-2, col, 0);
                        cout << "Replacing invalid cell content with default: o \n";
                    }
                }
            }
            row ++;
        }
        myfile.close();
    }
    nrows = dimensions.first;
    ncols = dimensions.second;
    set_current(field);
}

void GameOfLife::write_to_file(string outfile) {
    ofstream myOutfile;
    string output = current_to_string();
    myOutfile.open(outfile, ios::out);
    cout << "Saving state to " << outfile << endl;
    myOutfile << nrows << endl << ncols << endl << output;
    myOutfile.close();
}

void GameOfLife::get_random_field(const pair<int, int> dimensions) {
    Cell **randomField = get_dynamic_array(dimensions);
    for (int i=0; i< dimensions.first; i++) {
        for (int j=0; j< dimensions.second; j++) {
            int value = rand() % 2;
            randomField[i][j] = Cell(i, j, value);
        }
    }
    nrows = dimensions.first;
    ncols = dimensions.second;
    set_current(randomField);
}

string GameOfLife::current_to_string() {
    string matrixOut;
    for (int i=0; i<nrows; i++) {
        for (int j=0; j<ncols; j++) {
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
    int right = cell.get_right(this->ncols);
    int left = cell.get_left(this->ncols);
    int top = cell.get_top(this->nrows);
    int bottom = cell.get_bottom(this->nrows);
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
    Cell **nextGeneration = get_dynamic_array({nrows, ncols});
    for (int i=0; i< nrows; i++) {
        for (int j=0; j<ncols; j++) {
            Cell currentCell = currentGeneration[i][j];
            int aliveCount = count_living(currentCell);
            currentCell.evolve(aliveCount);
            nextGeneration[i][j] = currentCell;
        }
    }
    set_current(nextGeneration);
}
