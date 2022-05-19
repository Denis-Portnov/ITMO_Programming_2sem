#include "automat.h"

void Automat::doTurns(const vector<int> &turns, const int &step) {
    for (int turn: turns) {
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
        operations[step].push_back(turn);
    }
}

void Automat::step1() {
    int turnsCounter = 0;
    while (turnsCounter < 4) {
        vector<vector<vector<int>>> s = cube.sides;
        if (s[1][0][1] == Fcolor && s[5][2][1] == Dcolor) {
            doTurns({2, 2}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[2][0][1] == Rcolor && s[5][1][2] == Dcolor) {
            doTurns({4, 4}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[4][0][1] == Lcolor && s[5][1][0] == Dcolor) {
            doTurns({8, 8}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[3][0][1] == Bcolor && s[5][0][1] == Dcolor) {
            doTurns({6, 6}, 1);
            turnsCounter = 0;
            continue;
        }

        if (s[1][0][1] == Dcolor && s[5][2][1] == Fcolor) {
            doTurns({11, 5, 2, 4}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[2][0][1] == Dcolor && s[5][1][2] == Rcolor) {
            doTurns({11, 7, 4, 6}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[4][0][1] == Dcolor && s[5][1][0] == Lcolor) {
            doTurns({11, 3, 8, 2}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[3][0][1] == Dcolor && s[5][0][1] == Bcolor) {
            doTurns({11, 9, 6, 8}, 1);
            turnsCounter = 0;
            continue;
        }

        if (s[1][1][2] == Dcolor) {
            doTurns({3, 11, 2}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[2][1][2] == Dcolor) {
            doTurns({5, 11, 4}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[4][1][2] == Dcolor) {
            doTurns({9, 11, 8}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[3][1][2] == Dcolor) {
            doTurns({7, 11, 6}, 1);
            turnsCounter = 0;
            continue;
        }

        if (s[1][1][0] == Dcolor) {
            doTurns({2, 11, 3}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[2][1][0] == Dcolor) {
            doTurns({4, 11, 5}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[4][1][0] == Dcolor) {
            doTurns({8, 11, 9}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[3][1][0] == Dcolor) {
            doTurns({6, 11, 7}, 1);
            turnsCounter = 0;
            continue;
        }

        if (s[1][2][1] == Dcolor) {
            doTurns({2, 2, 11, 2, 2}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[2][2][1] == Dcolor) {
            doTurns({4, 4, 11, 4, 4}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[4][2][1] == Dcolor) {
            doTurns({8, 8, 11, 8, 8}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[3][2][1] == Dcolor) {
            doTurns({6, 6, 11, 6, 6}, 1);
            turnsCounter = 0;
            continue;
        }

        if (s[0][0][1] == Dcolor && s[1][2][1] != Fcolor) {
            doTurns({2, 2, 11, 2, 2}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[0][1][2] == Dcolor && s[2][2][1] != Rcolor) {
            doTurns({4, 4, 11, 4, 4}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[0][1][0] == Dcolor && s[4][2][1] != Lcolor) {
            doTurns({8, 8, 11, 8, 8}, 1);
            turnsCounter = 0;
            continue;
        }
        if (s[0][2][1] == Dcolor && s[3][2][1] != Bcolor) {
            doTurns({6, 6, 11, 6, 6}, 1);
            turnsCounter = 0;
            continue;
        }
        cube.Uturn();
        operations[1].push_back(10);
        ++turnsCounter;
    }
    for (int i = 0; i < 4; ++i) {
        operations[1].pop_back();
        cube.U_turn();
    }
}

void Automat::step2() {
    int turnsCounter = 0;
    while (turnsCounter < 4) {
        vector<vector<vector<int>>> s = cube.sides;
        if (s[1][2][1] == Fcolor && s[1][0][2] == Dcolor && s[5][2][2] == Fcolor && s[2][0][0] == Rcolor &&
            s[2][2][1] == Rcolor) {
            doTurns({3, 11, 2}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[1][0][0] == Fcolor && s[1][2][1] == Fcolor && s[4][0][2] == Dcolor && s[4][2][1] == Lcolor &&
            s[5][2][0] == Lcolor) {
            doTurns({9, 11, 8}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[2][0][2] == Dcolor && s[2][2][1] == Rcolor && s[5][0][2] == Rcolor && s[3][0][0] == Bcolor &&
            s[3][2][1] == Bcolor) {
            doTurns({5, 11, 4}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][0][2] == Dcolor && s[3][2][1] == Bcolor && s[5][0][0] == Bcolor && s[4][0][0] == Lcolor &&
            s[4][2][1] == Lcolor) {
            doTurns({7, 11, 6}, 2);
            turnsCounter = 0;
            continue;
        }

        if (s[1][0][2] == Fcolor && s[1][2][1] == Fcolor && s[5][2][2] == Rcolor && s[2][0][0] == Dcolor &&
            s[2][2][1] == Rcolor) {
            doTurns({4, 10, 5}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[1][0][0] == Dcolor && s[1][2][1] == Fcolor && s[5][2][0] == Fcolor && s[4][2][1] == Lcolor &&
            s[4][0][2] == Lcolor) {
            doTurns({2, 10, 3}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][0][0] == Dcolor && s[3][2][1] == Bcolor && s[5][0][2] == Bcolor && s[2][0][2] == Rcolor &&
            s[2][2][1] == Rcolor) {
            doTurns({6, 10, 7}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][0][2] == Bcolor && s[3][2][1] == Bcolor && s[5][0][0] == Lcolor && s[4][0][0] == Dcolor &&
            s[4][2][1] == Lcolor) {
            doTurns({8, 10, 9}, 2);
            turnsCounter = 0;
            continue;
        }

        if (s[1][2][1] == Fcolor && s[1][0][2] == Rcolor && s[5][2][2] == Dcolor && s[2][0][0] == Fcolor &&
            s[2][2][1] == Rcolor) {
            doTurns({4, 11, 5, 11, 11, 4, 10, 5}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[1][0][0] == Lcolor && s[1][2][1] == Fcolor && s[5][2][0] == Dcolor && s[4][0][2] == Fcolor &&
            s[4][2][1] == Lcolor) {
            doTurns({2, 11, 3, 11, 11, 2, 10, 3}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][0][0] == Rcolor && s[3][2][1] == Bcolor && s[5][0][2] == Dcolor && s[2][0][2] == Bcolor &&
            s[2][2][1] == Rcolor) {
            doTurns({6, 11, 7, 11, 11, 6, 10, 7}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][2][1] == Bcolor && s[3][0][2] == Lcolor && s[5][0][0] == Dcolor && s[4][0][0] == Bcolor &&
            s[4][2][1] == Lcolor) {
            doTurns({8, 11, 9, 11, 11, 8, 10, 9}, 2);
            turnsCounter = 0;
            continue;
        }

        if (s[1][2][1] == Fcolor && s[1][2][2] == Dcolor && s[2][2][1] == Rcolor) {
            doTurns({3, 11, 2}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[1][2][1] == Fcolor && s[4][2][1] == Lcolor && s[4][2][2] == Dcolor) {
            doTurns({9, 11, 8}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][2][1] == Bcolor && s[2][2][1] == Rcolor && s[2][2][2] == Dcolor) {
            doTurns({5, 11, 4}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][2][2] == Dcolor && s[3][2][1] == Bcolor && s[4][2][1] == Lcolor) {
            doTurns({7, 11, 6}, 2);
            turnsCounter = 0;
            continue;
        }

        if (s[1][2][1] == Fcolor && s[2][2][0] == Dcolor && s[2][2][1] == Rcolor) {
            doTurns({3, 11, 2}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[1][2][0] == Dcolor && s[1][2][1] == Fcolor && s[4][2][1] == Lcolor) {
            doTurns({9, 11, 8}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][2][0] == Dcolor && s[3][2][1] == Bcolor && s[2][2][1] == Rcolor) {
            doTurns({5, 11, 4}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][2][1] == Bcolor && s[4][2][0] == Dcolor && s[4][2][1] == Lcolor) {
            doTurns({7, 11, 6}, 2);
            turnsCounter = 0;
            continue;
        }

        if (s[4][2][1] == Lcolor && s[1][2][1] == Fcolor && s[0][0][0] == Dcolor &&
            (s[4][2][2] != Lcolor || s[1][2][0] != Fcolor)) {
            doTurns({2, 11, 3}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[2][2][1] == Rcolor && s[1][2][1] == Fcolor && s[0][0][2] == Dcolor &&
            (s[1][2][2] != Fcolor || s[2][2][0] != Rcolor)) {
            doTurns({4, 11, 5}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[4][2][1] == Lcolor && s[3][2][1] == Bcolor && s[0][2][0] == Dcolor &&
            (s[4][2][0] != Lcolor || s[3][2][2] != Bcolor)) {
            doTurns({8, 11, 9}, 2);
            turnsCounter = 0;
            continue;
        }
        if (s[3][2][1] == Bcolor && s[2][2][1] == Rcolor && s[0][2][2] == Dcolor &&
            (s[2][2][2] != Rcolor || s[3][2][0] != Bcolor)) {
            doTurns({6, 11, 7}, 2);
            turnsCounter = 0;
            continue;
        }
        cube.Uturn();
        operations[2].push_back(10);
        ++turnsCounter;
    }
    for (int i = 0; i < 4; ++i) {
        operations[2].pop_back();
        cube.U_turn();
    }
}

void Automat::step3() {
    bool matched = true;
    while (matched) {
        matched = false;
        int turnsCounter = 0;
        while (turnsCounter < 4) {
            vector<vector<vector<int>>> s = cube.sides;
            if (s[1][0][1] == Fcolor && s[5][2][1] == Lcolor) {
                doTurns({11, 9, 10, 8, 10, 2, 11, 3}, 3);
                turnsCounter = 0;
                continue;
            }
            if (s[2][0][1] == Rcolor && s[5][1][2] == Fcolor) {
                doTurns({11, 3, 10, 2, 10, 4, 11, 5}, 3);
                turnsCounter = 0;
                continue;
            }
            if (s[3][0][1] == Bcolor && s[5][0][1] == Rcolor) {
                doTurns({11, 5, 10, 4, 10, 6, 11, 7}, 3);
                turnsCounter = 0;
                continue;
            }
            if (s[4][0][1] == Lcolor && s[5][1][0] == Bcolor) {
                doTurns({11, 7, 10, 6, 10, 8, 11, 9}, 3);
                turnsCounter = 0;
                continue;
            }

            if (s[1][0][1] == Fcolor && s[5][2][1] == Rcolor) {
                doTurns({10, 4, 11, 5, 11, 3, 10, 2}, 3);
                turnsCounter = 0;
                continue;
            }
            if (s[4][0][1] == Lcolor && s[5][1][0] == Fcolor) {
                doTurns({10, 2, 11, 3, 11, 9, 10, 8}, 3);
                turnsCounter = 0;
                continue;
            }
            if (s[3][0][1] == Bcolor && s[5][0][1] == Lcolor) {
                doTurns({10, 8, 11, 9, 11, 7, 10, 6}, 3);
                turnsCounter = 0;
                continue;
            }
            if (s[2][0][1] == Rcolor && s[5][1][2] == Bcolor) {
                doTurns({10, 6, 11, 7, 11, 5, 10, 4}, 3);
                turnsCounter = 0;
                continue;
            }

            cube.Uturn();
            operations[3].push_back(10);
            ++turnsCounter;
        }
        for (int i = 0; i < 4; ++i) {
            operations[3].pop_back();
            cube.U_turn();
        }

        if (cube.sides[1][1][2] != Fcolor || cube.sides[2][1][0] != Rcolor) {
            doTurns({10, 4, 11, 5, 11, 3, 10, 2}, 3);
            matched = true;
            continue;
        }
        if (cube.sides[1][1][0] != Fcolor || cube.sides[4][1][2] != Lcolor) {
            doTurns({10, 2, 11, 3, 11, 9, 10, 8}, 3);
            matched = true;
            continue;
        }
        if (cube.sides[3][1][2] != Bcolor || cube.sides[4][1][0] != Lcolor) {
            doTurns({10, 8, 11, 9, 11, 7, 10, 6}, 3);
            matched = true;
            continue;
        }
        if (cube.sides[3][1][0] != Bcolor || cube.sides[2][1][2] != Rcolor) {
            doTurns({10, 6, 11, 7, 11, 5, 10, 4}, 3);
            matched = true;
            continue;
        }
    }
}

void Automat::step4() {
    vector<vector<vector<int>>> s = cube.sides;
    if (s[1][0][1] == Ucolor && s[2][0][1] == Ucolor && s[5][0][1] == Ucolor && s[5][1][0] == Ucolor) {
        doTurns({2, 10, 4, 11, 5, 3}, 4);
    }
    if (s[1][0][1] == Ucolor && s[4][0][1] == Ucolor && s[5][0][1] == Ucolor && s[5][1][2] == Ucolor) {
        doTurns({8, 10, 2, 11, 3, 9}, 4);
    }
    if (s[3][0][1] == Ucolor && s[2][0][1] == Ucolor && s[5][1][0] == Ucolor && s[5][2][1] == Ucolor) {
        doTurns({4, 10, 6, 11, 7, 5}, 4);
    }
    if (s[3][0][1] == Ucolor && s[4][0][1] == Ucolor && s[5][1][2] == Ucolor && s[5][2][1] == Ucolor) {
        doTurns({6, 10, 8, 11, 9, 7}, 4);
    }
    if (s[1][0][1] == Ucolor && s[3][0][1] == Ucolor && s[5][1][0] == Ucolor && s[5][1][2] == Ucolor) {
        doTurns({2, 4, 10, 5, 11, 3}, 4);
    }
    if (s[4][0][1] == Ucolor && s[2][0][1] == Ucolor && s[5][0][1] == Ucolor && s[5][2][1] == Ucolor) {
        doTurns({4, 6, 10, 7, 11, 5}, 4);
    }
    if (s[1][0][1] == Ucolor && s[2][0][1] == Ucolor && s[3][0][1] == Ucolor && s[4][0][1] == Ucolor) {
        doTurns({2, 10, 4, 11, 5, 3, 4, 6, 10, 7, 11, 5}, 4);
    }
}

void Automat::step5() {
    if (cube.sides[2][0][1] == Fcolor) {
        doTurns({10, 9, 10, 10, 8, 10, 9, 10, 8}, 5);
    }
    if (cube.sides[4][0][1] == Fcolor) {
        doTurns({10, 7, 10, 10, 6, 10, 7, 10, 6}, 5);
    }
    if (cube.sides[3][0][1] == Fcolor) {
        doTurns({10, 5, 10, 10, 4, 10, 5, 10, 4, 10, 7, 10, 10, 6, 10, 7, 10, 6, 10, 5, 10, 10, 4, 10, 5, 10, 4}, 5);
    }
    if (cube.sides[3][0][1] == Rcolor) {
        doTurns({10, 3, 10, 10, 2, 10, 3, 10, 2}, 5);
    }
    if (cube.sides[4][0][1] == Rcolor) {
        doTurns({10, 7, 10, 10, 6, 10, 7, 10, 6, 10, 9, 10, 10, 8, 10, 9, 10, 8, 10, 7, 10, 10, 6, 10, 7, 10, 6}, 5);
    }
    if (cube.sides[4][0][1] == Bcolor) {
        doTurns({10, 5, 10, 10, 4, 10, 5, 10, 4}, 5);
    }
}

void Automat::step6() {
    if ((cube.sides[1][0][0] == Rcolor && cube.sides[5][2][0] == Ucolor && cube.sides[4][0][2] == Fcolor) ||
        (cube.sides[1][0][0] == Rcolor && cube.sides[5][2][0] == Fcolor && cube.sides[4][0][2] == Ucolor) ||
        (cube.sides[1][0][0] == Fcolor && cube.sides[5][2][0] == Ucolor && cube.sides[4][0][2] == Rcolor) ||
        (cube.sides[1][0][0] == Fcolor && cube.sides[5][2][0] == Rcolor && cube.sides[4][0][2] == Ucolor) ||
        (cube.sides[1][0][0] == Ucolor && cube.sides[5][2][0] == Rcolor && cube.sides[4][0][2] == Fcolor) ||
        (cube.sides[1][0][0] == Ucolor && cube.sides[5][2][0] == Fcolor && cube.sides[4][0][2] == Rcolor)) {
        doTurns({3, 9, 2, 5, 3, 8, 2, 4}, 6);
    }
    if ((cube.sides[2][0][2] == Fcolor && cube.sides[5][0][2] == Ucolor && cube.sides[3][0][0] == Rcolor) ||
        (cube.sides[2][0][2] == Fcolor && cube.sides[5][0][2] == Rcolor && cube.sides[3][0][0] == Ucolor) ||
        (cube.sides[2][0][2] == Rcolor && cube.sides[5][0][2] == Ucolor && cube.sides[3][0][0] == Fcolor) ||
        (cube.sides[2][0][2] == Rcolor && cube.sides[5][0][2] == Fcolor && cube.sides[3][0][0] == Ucolor) ||
        (cube.sides[2][0][2] == Ucolor && cube.sides[5][0][2] == Fcolor && cube.sides[3][0][0] == Rcolor) ||
        (cube.sides[2][0][2] == Ucolor && cube.sides[5][0][2] == Rcolor && cube.sides[3][0][0] == Fcolor)) {
        doTurns({5, 3, 9, 2, 4, 3, 8, 2}, 6);
    }
    if ((cube.sides[3][0][2] == Fcolor && cube.sides[5][0][0] == Ucolor && cube.sides[4][0][0] == Rcolor) ||
        (cube.sides[3][0][2] == Fcolor && cube.sides[5][0][0] == Rcolor && cube.sides[4][0][0] == Ucolor) ||
        (cube.sides[3][0][2] == Rcolor && cube.sides[5][0][0] == Fcolor && cube.sides[4][0][0] == Ucolor) ||
        (cube.sides[3][0][2] == Rcolor && cube.sides[5][0][0] == Ucolor && cube.sides[4][0][0] == Fcolor) ||
        (cube.sides[3][0][2] == Ucolor && cube.sides[5][0][0] == Rcolor && cube.sides[4][0][0] == Fcolor) ||
        (cube.sides[3][0][2] == Ucolor && cube.sides[5][0][0] == Fcolor && cube.sides[4][0][0] == Rcolor)) {
        doTurns({3, 9, 7, 8, 2, 9, 6, 8}, 6);
    }
    if ((cube.sides[4][0][2] == Rcolor && cube.sides[5][2][0] == Ucolor && cube.sides[1][0][0] == Bcolor) ||
        (cube.sides[4][0][2] == Rcolor && cube.sides[5][2][0] == Bcolor && cube.sides[1][0][0] == Ucolor) ||
        (cube.sides[4][0][2] == Ucolor && cube.sides[5][2][0] == Rcolor && cube.sides[1][0][0] == Bcolor) ||
        (cube.sides[4][0][2] == Ucolor && cube.sides[5][2][0] == Bcolor && cube.sides[1][0][0] == Rcolor) ||
        (cube.sides[4][0][2] == Bcolor && cube.sides[5][2][0] == Ucolor && cube.sides[1][0][0] == Rcolor) ||
        (cube.sides[4][0][2] == Bcolor && cube.sides[5][2][0] == Rcolor && cube.sides[1][0][0] == Ucolor)) {
        doTurns({7, 5, 6, 9, 7, 4, 6, 8}, 6);
    }
    if ((cube.sides[3][0][2] == Rcolor && cube.sides[5][0][0] == Ucolor && cube.sides[4][0][0] == Bcolor) ||
        (cube.sides[3][0][2] == Rcolor && cube.sides[5][0][0] == Bcolor && cube.sides[4][0][0] == Ucolor) ||
        (cube.sides[3][0][2] == Ucolor && cube.sides[5][0][0] == Rcolor && cube.sides[4][0][0] == Bcolor) ||
        (cube.sides[3][0][2] == Ucolor && cube.sides[5][0][0] == Bcolor && cube.sides[4][0][0] == Rcolor) ||
        (cube.sides[3][0][2] == Bcolor && cube.sides[5][0][0] == Ucolor && cube.sides[4][0][0] == Rcolor) ||
        (cube.sides[3][0][2] == Bcolor && cube.sides[5][0][0] == Rcolor && cube.sides[4][0][0] == Ucolor)) {
        doTurns({9, 7, 5, 6, 8, 7, 4, 6}, 6);
    }
};

int Automat::step7() {
    if (cube.sides[2][0][0] == Ucolor) {
        doTurns({3, 4, 2, 5, 3, 4, 2, 5}, 7);
    } else {
        if (cube.sides[1][0][2] == Ucolor) {
            doTurns({4, 3, 5, 2, 4, 3, 5, 2}, 7);
        } else {
            cube.Uturn();
            operations[7].push_back(10);
        }
    }
    if (cube.sides[2][0][0] == Ucolor) {
        doTurns({3, 4, 2, 5, 3, 4, 2, 5}, 7);
    } else {
        if (cube.sides[1][0][2] == Ucolor) {
            doTurns({4, 3, 5, 2, 4, 3, 5, 2}, 7);
        }
    }
    cube.Uturn();
    operations[7].push_back(10);
    if (cube.sides[2][0][0] == Ucolor) {
        doTurns({3, 4, 2, 5, 3, 4, 2, 5}, 7);
    } else {
        if (cube.sides[1][0][2] == Ucolor) {
            doTurns({4, 3, 5, 2, 4, 3, 5, 2}, 7);
        }
    }
    cube.Uturn();
    operations[7].push_back(10);
    if (cube.sides[2][0][0] == Ucolor) {
        doTurns({3, 4, 2, 5, 3, 4, 2, 5}, 7);
    } else {
        if (cube.sides[1][0][2] == Ucolor) {
            doTurns({4, 3, 5, 2, 4, 3, 5, 2}, 7);
        }
    }
    cube.Uturn();
    operations[7].push_back(10);
    if (cube.sides[2][0][0] == Ucolor) {
        doTurns({3, 4, 2, 5, 3, 4, 2, 5}, 7);
    } else {
        if (cube.sides[1][0][2] == Ucolor) {
            doTurns({4, 3, 5, 2, 4, 3, 5, 2}, 7);
        }
    }
    int turnscount = 0;
    while (!cube.IsSolved() && turnscount < 5) {
        ++turnscount;
        cube.Uturn();
        operations[7].push_back(10);
    }
    if (turnscount == 5) {
        return 1;
    }
    return 0;
}

Automat Automat::Solver() {
    operations.assign(8, vector<int>());
    step1();
    step2();
    step3();
    step4();
    step5();
    step6();
    if (step7()) {
        operations = vector<vector<int>>{};
    }
    return *this;
}