#pragma once

#include "Figure.h"

using namespace std;

class Rectangle : public Figure {
private:
    CVector2D A, B, C, D;
    double weight = 0;
    const char *name = "Прямоугольник";

public:
    Rectangle();

    double square() override;

    double perimeter() override;

    double mass() const override;

    CVector2D position() const override;

    const char *className() override;

    unsigned int size() override;

    void draw() override;

    void initFromDialogue() override;

    bool operator==(const IPhysObject &obj) const override;

    bool operator<(const IPhysObject &obj) const override;
};


