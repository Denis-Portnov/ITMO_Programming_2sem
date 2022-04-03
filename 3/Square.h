#pragma once

#include <iostream>
#include "vec.h"

namespace square {

    class Square {

    private:
        float S;
        float x, y;
        float side;
        int a;

    public:

        Square(float x0, float y0, float AB, int alpha) {
            x = x0;
            y = y0;
            side = AB;
            a = alpha;
            S = side * side;
        }

        void param() const;

        friend Square operator*(Square square, float x);

        friend Square operator*(float x, Square square);

        friend Square operator+(Square square, const vec::Vector &v);

        friend Square operator+(const vec::Vector &v, Square square);

        friend bool operator==(const Square &square1, const Square &square2);

        friend bool operator>(const Square &square1, const Square &square2);

        friend bool operator<(const Square &square1, const Square &square2);

        friend bool operator!=(const Square &square1, const Square &square2);

    };
}




