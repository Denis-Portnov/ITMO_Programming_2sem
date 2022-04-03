#pragma once
namespace fun {
    struct Circle {
        float x0, y0;
    };
    struct Vector {
        float x, y;
    };

    void whole_1(float *);

    void whole_2(float &);

    void change_f1(float *);

    void change_f2(float &);

    void change_i1(int *);

    void change_i2(int &);

    void matrix_1(float *, float);

    void matrix_2(float (&)[3][3], float);

    void move_1(Circle *, Vector *);

    void move_2(Circle &, Vector &);

}