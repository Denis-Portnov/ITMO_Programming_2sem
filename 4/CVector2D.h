#pragma once

class CVector2D {
public:
    double x;
    double y;

    CVector2D() : x(0), y(0) {};

    friend std::istream &operator>>(std::istream &, CVector2D &);

    friend std::ostream &operator<<(std::ostream &, const CVector2D &);
};
