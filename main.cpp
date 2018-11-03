#include <iostream>
#include <array>

using namespace std;

array<array<int,30>,30> get_static_array(){
    array<array<int,30>,30> statArray;
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            statArray[i][j] = rand() % 10;
        }
    }
    return statArray;
}

int **get_dynamic_array(){
    int **dynArray;
    dynArray = new int*[30];
    for (int i=0; i<30; i++) {
        dynArray[i] = new int[30];
    }
    return dynArray;
}

void print_array(array<array<int,30>,30> s) {
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
};

void print_array(int **d) {
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
};

void copy_to_dynamic(array<array<int,30>,30> s, int **d) {
    print_array(s);
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            d[i][j] = s[i][j];
        }
    }
    print_array(d);
}

void userCtrl() {
    bool isFilledD = false;
    bool alive = true;
    array<array<int,30>,30> s = get_static_array();
    int **d = get_dynamic_array();
    while (alive) {
        int cmd;
        cout << "Enter a command. Your options are:" << endl << "0: create static array" << endl << "1: create dynamic array" << endl
             << "2: copy static to dynamic array" << endl << "3: print static array" << endl << "4: print dynamic array" << endl
             << "5: exit" << endl << ">>";
        cin >> cmd;
        switch (cmd)
        {
        case 0: { s = get_static_array(); break; }
        case 1: { d = get_dynamic_array(); isFilledD = false; break; }
        case 2: { copy_to_dynamic(s, d); isFilledD = true; break; }
        case 3: { print_array(s); break; }
        case 4: { if (isFilledD) print_array(s); else { cout << "You need to fill the dynamic array first \n"; } break; }
        case 5: {alive = false; break;}
        default: cout << "Try again \n";
        }
    }
}

int main()
{
    userCtrl();
    return 0;
}
