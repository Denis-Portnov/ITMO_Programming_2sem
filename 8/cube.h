#pragma once

#include <vector>
#include <string>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <set>

using namespace std;

class Cube {
public:
    vector<vector<vector<int>>> sides;

    Cube() {
        sides.assign(6, vector<vector<int>>(3, vector<int>(3)));
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    sides[i][j][k] = i;
    }

    bool IsSolved();

    void Dturn();

    void D_turn();

    void Fturn();

    void F_turn();

    void Rturn();

    void R_turn();

    void Bturn();

    void B_turn();

    void Lturn();

    void L_turn();

    void Uturn();

    void U_turn();
};



