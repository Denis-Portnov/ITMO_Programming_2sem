#include "cube.h"

bool Cube::IsSolved() {
    for (int k = 0; k < 6; ++k) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (sides[k][i][j] != sides[k][1][1]) {
                    return false;
                }
            }
        }
    }
    return true;
}


