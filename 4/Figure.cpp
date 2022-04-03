#include "Figure.h"

std::istream &operator>>(std::istream &input, CVector2D &vector2D) {
    input >> vector2D.x >> vector2D.y;
    return input;
}

std::ostream &operator<<(std::ostream &output, const CVector2D &vector2D) {
    output << "(" << vector2D.x << "; " << vector2D.y << ")";
    return output;
}
