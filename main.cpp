#include "gameoflife.h"
#include <unistd.h>

void print_main_menu() {
    cout << "MENU \n";
    cout << "Choose an action: \n";
    cout << "A: Import custom state. \n";
    cout << "B: Generate new random state.\n";
    cout << "C: Export current state to a file. \n";
    cout << "D: Start evolution. \n";
    cout << "E: Change a particular cell. \n";
    cout << "F: Exit. \n";
    cout << ">>>";
}

GameOfLife import_wrapper(GameOfLife game) {
    cout << "Enter the path to your file: \n>>>";
    string input;
    cin >> input;
    ifstream file(input);
    if (file.good()) {
        game.import_state(input);
        cout << "Import successful.\n";
    } else cout << "Something went wrong.\n";
    return game;
}

GameOfLife random_start_wrapper(GameOfLife game) {
    cout << "Default field size is 30x30. Modify field size? [Y/N] \n >>>";
    string input;
    cin >> input;
    if (input == "Y") {
        cout << "Enter number of rows: \n>>>";
        cin >> input;
        size_t nrows = stoul(input);
        cout << "Enter number of columns: \n>>>";
        cin >> input;
        size_t ncols = stoul(input);
        game.change_field_size(nrows, ncols);
    }
    game.get_random_field();
    cout << "Successfully generated random state. \n";
    return game;
}

GameOfLife export_wrapper(GameOfLife game) {
    cout << "Enter export path: \n>>>";
    string input;
    cin >> input;
    game.write_to_file(input);
    ifstream fileTest(input);
    if (fileTest.good()) cout << "Export successful. \n";
    else cout << "Something went wrong. \n";
    return game;
}

GameOfLife evolution_wrapper(GameOfLife game) {
    cout << "Enter number of steps: \n>>>";
    string input;
    cin >> input;
    int nSteps = stoi(input);
    cout << "Starting evolution. \n";
    int i = 0;
    while (i < nSteps) {
        game.evolve();
        game.print_current();
        usleep(80000);
        i++;
    }
    return game;
}

GameOfLife change_cell_wrapper(GameOfLife game) {
    string input;
    cout << "Enter row of cell: \n>>>";
    cin >> input;
    size_t row = stoul(input) - 1;
    cout << "Enter column of cell: \n>>>";
    cin >> input;
    size_t col = stoul(input) - 1;
    if (row >= game.nrows || col >= game.ncols) {
        cout << "Invalid row or column.";
    } else {
        cout << "Enter new value of cell: [*/o] \n >>>";
        cin >> input;
        game.currentGeneration[row][col].set_status(input.front());
        cout << "Change successful. \n";
    }
    return game;
}

GameOfLife console(GameOfLife game) {
    print_main_menu();
    string input;
    cin >> input;
    if (input == "A") return import_wrapper(game);
    else if (input == "B") return random_start_wrapper(game);
    else if (input == "C") return export_wrapper(game);
    else if (input == "D") return evolution_wrapper(game);
    else if (input == "E") return change_cell_wrapper(game);
    else if (input == "F") { cout << "Bye! \n"; abort(); }
    else {cout << "Try again";}
    return game;
}

int main() {
    GameOfLife game = GameOfLife();
    while (true){
        cout << "Current state is: \n \n";
        game.print_current();
        game = console(game);
    }
}

