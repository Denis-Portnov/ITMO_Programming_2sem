#include "UserDialogue.h"

bool UserDialogue::IsCorrect(const int &color, const ifstream &fin) {
    if (fin.eof() or color < 0 or color > 5) {
        cout << "Wrong file's content\n";
        return false;
    }
    return true;
}

void UserDialogue::ReadCubeFromFile() {
    char *f = new char[100];
    cout << "Input the file's name: ";
    cin >> f;
    ifstream fin(f);
    if (!fin) {
        cout << "Can not open such file\n";
        return;
    }
    char s;
    int color;
    Cube newCube;
    for (int i = 0; i < 3; i++) {
        fin >> s;
        for (int j = 0; j < 3; j++) {
            fin >> color;
            if (IsCorrect(color, fin)) {
                newCube.sides[5][i][j] = color;
            }
        }
        fin >> s;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            fin >> color;
            if (IsCorrect(color, fin)) {
                newCube.sides[4][i][j] = color;
            }
        }
        fin >> s;
        for (int j = 0; j < 3; ++j) {
            fin >> color;
            if (IsCorrect(color, fin)) {
                newCube.sides[1][i][j] = color;
            }
        }
        fin >> s;
        for (int j = 0; j < 3; ++j) {
            fin >> color;
            if (IsCorrect(color, fin)) {
                newCube.sides[2][i][j] = color;
            }
        }
        fin >> s;
        for (int j = 0; j < 3; ++j) {
            fin >> color;
            if (IsCorrect(color, fin)) {
                newCube.sides[3][i][j] = color;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        fin >> s;
        for (int j = 0; j < 3; j++) {
            fin >> color;
            if (IsCorrect(color, fin)) {
                newCube.sides[0][i][j] = color;
            }
        }
        fin >> s;
    }
    fin.close();
    delete[] f;
    Automat au(newCube);
    if (au.Solver().getOperations().empty()) {
        cout << "Cube is not correct!\n";
        return;
    }
    cube.sides = newCube.sides;

}

void UserDialogue::Print() {
    for (int i = 0; i < 3; ++i) {
        cout << "      | ";
        for (int j = 0; j < 3; ++j) {
            cout << cube.sides[5][i][j] << ' ';
        }

        cout << "|\n";
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << cube.sides[4][i][j] << ' ';
        }
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << cube.sides[1][i][j] << ' ';
        }
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << cube.sides[2][i][j] << ' ';
        }
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << cube.sides[3][i][j] << ' ';
        }
        cout << "\n";
    }
    for (int i = 0; i < 3; ++i) {
        cout << "      | ";
        for (int j = 0; j < 3; ++j) {
            cout << cube.sides[0][i][j] << ' ';
        }
        cout << "|\n";
    }
}

void UserDialogue::ReadTurns() {
    cout << "Enter commands. To stop, enter *\n";
    cout << "Commands: R, R', L, L', U, U', D, D', F, F', B, B', where ' means back turn\n";
    string turn;
    while (true) {
        cin >> turn;
        if (turn == "R") {
            cube.Rturn();
            continue;
        }
        if (turn == "R'") {
            cube.R_turn();
            continue;
        }
        if (turn == "L") {
            cube.Lturn();
            continue;
        }
        if (turn == "L'") {
            cube.L_turn();
            continue;
        }
        if (turn == "U") {
            cube.Uturn();
            continue;
        }
        if (turn == "U'") {
            cube.U_turn();
            continue;
        }
        if (turn == "D") {
            cube.Dturn();
            continue;
        }
        if (turn == "D'") {
            cube.D_turn();
            continue;
        }
        if (turn == "F") {
            cube.Fturn();
            continue;
        }
        if (turn == "F'") {
            cube.F_turn();
            continue;
        }
        if (turn == "B") {
            cube.Bturn();
            continue;
        }
        if (turn == "B'") {
            cube.B_turn();
            continue;
        }
        if (turn == "*") {
            return;
        }
        cout << "Wrong command. Commands: R, R', L, L', U, U', D, D', F, F', B, B', where ' means back turn\n";
    }
}

void UserDialogue::GenerateRandomCube() {
    srand(time(nullptr));
    for (int i = 0; i < 40; ++i) {
        int turn = rand() % 12;
        switch (turn) {
            case 0: {
                cube.Dturn();
                break;
            }
            case 1: {
                cube.D_turn();
                break;
            }
            case 2: {
                cube.Fturn();
                break;
            }
            case 3: {
                cube.F_turn();
                break;
            }
            case 4: {
                cube.Rturn();
                break;
            }
            case 5: {
                cube.R_turn();
                break;
            }
            case 6: {
                cube.Bturn();
                break;
            }
            case 7: {
                cube.B_turn();
                break;
            }
            case 8: {
                cube.Lturn();
                break;
            }
            case 9: {
                cube.L_turn();
                break;
            }
            case 10: {
                cube.Uturn();
                break;
            }
            case 11: {
                cube.U_turn();
                break;
            }
            default: {
                break;
            }
        }
    }
}

void UserDialogue::SolveCube() {
    Automat au = Automat(cube);
    Automat newCube = au.Solver();
    cube = newCube.getCube();
    vector<vector<int>> operations = newCube.getOperations();
    for (int i = 1; i < operations.size(); ++i) {
        cout << "step " << i << ": ";
        for (auto oper: operations[i]) {
            switch (oper) {
                case 0: {
                    cout << "D ";
                    break;
                }
                case 1: {
                    cout << "D' ";
                    break;
                }
                case 2: {
                    cout << "F ";
                    break;
                }
                case 3: {
                    cout << "F' ";
                    break;
                }
                case 4: {
                    cout << "R ";
                    break;
                }
                case 5: {
                    cout << "R' ";
                    break;
                }
                case 6: {
                    cout << "B ";
                    break;
                }
                case 7: {
                    cout << "B' ";
                    break;
                }
                case 8: {
                    cout << "L ";
                    break;
                }
                case 9: {
                    cout << "L' ";
                    break;
                }
                case 10: {
                    cout << "U ";
                    break;
                }
                case 11: {
                    cout << "U' ";
                    break;
                }
                default: {
                    break;
                }
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void UserDialogue::SaveCurrentCubeInFile() {
    char *f = new char[100];
    cout << "Input the file's name: ";
    cin >> f;
    ofstream fout(f);
    if (!fout) {
        cout << "Can not open such file\n";
        return;
    }
    for (int i = 0; i < 3; ++i) {
        fout << "      | ";
        for (int j = 0; j < 3; ++j) {
            fout << cube.sides[5][i][j] << ' ';
        }

        fout << "|\n";
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            fout << cube.sides[4][i][j] << ' ';
        }
        fout << "| ";
        for (int j = 0; j < 3; ++j) {
            fout << cube.sides[1][i][j] << ' ';
        }
        fout << "| ";
        for (int j = 0; j < 3; ++j) {
            fout << cube.sides[2][i][j] << ' ';
        }
        fout << "| ";
        for (int j = 0; j < 3; ++j) {
            fout << cube.sides[3][i][j] << ' ';
        }
        fout << "\n";
    }
    for (int i = 0; i < 3; ++i) {
        fout << "      | ";
        for (int j = 0; j < 3; ++j) {
            fout << cube.sides[0][i][j] << ' ';
        }
        fout << "|\n";
    }
    fout.close();
}


void UserDialogue::Menu() {
    while (true) {
        cout << "1. Read cube from file\n";
        cout << "2. Show the cube\n";
        cout << "3. Enter turns\n";
        cout << "4. Generate random cube\n";
        cout << "5. Solve current cube\n";
        cout << "6. Save current cube in file\n";
        cout << "0. Exit\n";
        cout << "> ";
        int operation;
        cin >> operation;
        switch (operation) {
            case 1: {
                ReadCubeFromFile();
                break;
            }
            case 2: {
                Print();
                break;
            }
            case 3: {
                ReadTurns();
                break;
            }
            case 4: {
                GenerateRandomCube();
                break;
            }
            case 5: {
                SolveCube();
                break;
            }
            case 6: {
                SaveCurrentCubeInFile();
                break;
            }
            case 0: {
                exit(0);
            }
            default: {
                cout << "Wrong command\n";
                break;
            }
        }
        if (operation != 0) {
            system("read -n 5 -s -p \"Press 'Enter' to continue...\"");
        }
    }
}