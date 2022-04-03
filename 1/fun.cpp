#include "fun.h"

namespace fun {
    void whole_1(float *tx) {
        *tx = (int) *tx;
    }

    void whole_2(float &tx) {
        tx = (int) tx;
    }

    void change_f1(float *tx) {
        *tx = -*tx;
    }

    void change_f2(float &tx) {
        tx = -tx;
    }

    void change_i1(int *tx) {
        *tx = -*tx;
    }

    void change_i2(int &tx) {
        tx = -tx;
    }

    void matrix_1(float *tp, float tk) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                *(tp + i * 3 + j) *= tk;
            }
        }
    }

    void matrix_2(float (&tarr)[3][3], float tk) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tarr[i][j] *= tk;
            }
        }
    }

    void move_1(Circle *c, Vector *v) {
        c->x0 += v->x;
        c->y0 += v->y;
    }

    void move_2(Circle &c, Vector &v) {
        c.x0 += v.x;
        c.y0 += v.y;
    }
}
