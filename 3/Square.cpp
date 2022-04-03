#include "Square.h"

namespace square {

    bool operator==(const Square &square1, const Square &square2) {
        return (square1.S == square2.S);
    }

    bool operator>(const Square &square1, const Square &square2) {
        return (square1.S > square2.S);
    }

    bool operator<(const Square &square1, const Square &square2) {
        return (square1.S < square2.S);
    }

    bool operator!=(const Square &square1, const Square &square2) {
        return !(square1 == square2);
    }


    Square operator*(Square square, float x) {
        square.side *= x;
        square.S = square.side * square.side;
        return square;
    }

    Square operator*(float x, Square square) {
        return operator*(square, x);
    }

    Square operator+(Square square, const vec::Vector &v) {
        square.x += v.x;
        square.y += v.y;
        return square;
    }

    Square operator+(const vec::Vector &v, Square square) {
        return operator+(square, v);
    }

    void Square::param() const {
        std::cout << "Площадь: " << S << '\n'
                  << "Координаты: (" << x << ", " << y << ')' << '\n'
                  << "Сторона: " << side << '\n'
                  << "Угол: " << a << '\n';
    }
}