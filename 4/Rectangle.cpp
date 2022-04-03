#include "Rectangle.h"

Rectangle::Rectangle() {
    this->Rectangle::initFromDialogue();
}

double Rectangle::square() {
    double AB = pow(pow(B.x - A.x, 2) - pow(B.y - A.y, 2), 0.5);
    double BC = pow(pow(C.x - B.x, 2) - pow(C.y - B.y, 2), 0.5);
    return AB * BC;
}


double Rectangle::perimeter() {
    double AB = pow(pow(B.x - A.x, 2) - pow(B.y - A.y, 2), 0.5);
    double BC = pow(pow(C.x - B.x, 2) - pow(C.y - B.y, 2), 0.5);
    return 2 * (AB + BC);
}

double Rectangle::mass() const {
    return weight;
}

CVector2D Rectangle::position() const {
    CVector2D centre;
    centre.x = (A.x + D.x) / 2;
    centre.y = (A.y + B.y) / 2;
    return centre;

}

const char *Rectangle::className() {
    return name;
}

unsigned int Rectangle::size() {
    return sizeof(*this);
}

void Rectangle::draw() {
    cout << "Имя: " << name << '\n';
    cout << "Позиция: " << position() << '\n';
    cout << "Вес: " << weight << '\n';
    cout << "Размер: " << size() << "\n\n";
}

void Rectangle::initFromDialogue() {
    cout << "\tВведите координаты для первой вершины: ";
    cin >> A;
    cout << "\tВведите координаты для второй вершины: ";
    cin >> B;
    cout << "\tВведите координаты для третьей вершины: ";
    cin >> C;
    cout << "\tВведите координаты для четвертой вершины: ";
    cin >> D;
    cout << "\tВведите вес: ";
    cin >> weight;
    cout << '\n';
}

bool Rectangle::operator==(const IPhysObject &obj) const {
    return mass() == obj.mass();
}

bool Rectangle::operator<(const IPhysObject &obj) const {
    return mass() < obj.mass();
}
