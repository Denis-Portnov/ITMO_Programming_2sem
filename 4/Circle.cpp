#include "Circle.h"

double pi = M_PI;

Circle::Circle() {
    this->Circle::initFromDialogue();
}

double Circle::square() {
    return pi * radius * radius;
}

double Circle::perimeter() {
    return 2 * pi * radius;
}

double Circle::mass() const {
    return weight;
}

CVector2D Circle::position() const {
    return centre;
}

const char *Circle::className() {
    return name;
}

unsigned Circle::size() {
    return sizeof(*this);
}

void Circle::draw() {
    cout << "Название фигуры: " << name << '\n';
    cout << "Позиция: " << centre << '\n';
    cout << "Радиус: " << radius << '\n';
    cout << "Вес: " << weight << '\n';
    cout << "Размер: " << size() << "\n\n";
}

void Circle::initFromDialogue() {
    cout << "\tВведите координаты центра (x и y): ";
    cin >> centre;
    cout << "\tВведите радиус: ";
    cin >> radius;
    cout << "\tВведите вес: ";
    cin >> weight;
    cout << '\n';
}

bool Circle::operator==(const IPhysObject &object) const {
    return mass() == object.mass();
}

bool Circle::operator<(const IPhysObject &object) const {
    return mass() < object.mass();
}
