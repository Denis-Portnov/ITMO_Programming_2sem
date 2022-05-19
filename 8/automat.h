#pragma once

#include "turns.h"

using namespace std;

class Automat {

public:
    explicit Automat(const Cube &c) {
        cube = c;
        Dcolor = cube.sides[0][1][1];
        Fcolor = cube.sides[1][1][1];
        Rcolor = cube.sides[2][1][1];
        Bcolor = cube.sides[3][1][1];
        Lcolor = cube.sides[4][1][1];
        Ucolor = cube.sides[5][1][1];
    }


    Automat Solver();

    Cube getCube() {
        return cube;
    }

    vector<vector<int>> getOperations() {
        return operations;
    }

private:
    Cube cube;
    int Dcolor, Rcolor, Fcolor, Bcolor, Lcolor, Ucolor;
    vector<vector<int>> operations;

    void doTurns(const vector<int> &turns, const int &step);

    void step1();

    void step2();

    void step3();

    void step4();

    void step5();

    void step6();

    int step7();
};

