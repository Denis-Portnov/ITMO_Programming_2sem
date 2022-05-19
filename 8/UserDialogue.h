#pragma once

#include "iostream"
#include "automat.h"
#include "fstream"

using namespace std;

class UserDialogue {
public:
    Cube cube;

    UserDialogue() {
        cube = Cube();
        Menu();
    }

    void Print();

    void Menu();

    void GenerateRandomCube();

    void ReadTurns();

    void ReadCubeFromFile();

    static bool IsCorrect(const int &color, const ifstream &fin);

    void SolveCube();

    void SaveCurrentCubeInFile();
};


