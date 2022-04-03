#include <iostream>
#include "Arr.h"
#include "Square.h"

int main() {
//    std::cout << "-------------------" << '\n';
//    std::cout << "---- Задание 6 ----" << '\n';
//    std::cout << "-------------------" << '\n';
//
//    arr::Arr a(2), b(3), c, d;
//    a.Arr_Cin();
//    std::cout << "Массив а: ";
//    a.Arr_Cout();
//    b.Arr_Cin();
//    std::cout << "Массив b: ";
//    b.Arr_Cout();
//
//    c = a + b;
//    std::cout << "Массив c: ";
//    c.Arr_Cout();
//
//    d = operator+(c, a);
//    std::cout << "Массив d: ";
//    d.Arr_Cout();
//
//    bool t = a == b;
//    std::cout << "a == b: " << t << "\n\n\n\n\n\n\n";
//
//
//    std::cout << "-------------------" << '\n';
//    std::cout << "---- Задание 2 ----" << '\n';
//    std::cout << "-------------------" << '\n';
//
//    square::Square sq_1(3, 4, 15, 20);
//    square::Square sq_2(4, 5, 15, 25);
//
//    bool t_sq = sq_1 == sq_2;
//    std::cout << "S_1 == S_2: " << t_sq << '\n';
//
//    std::cout << '\n' << "Изначальные параметры квадрата:\n";
//    sq_1.param();
//
//    sq_1 = sq_1 * 2;
//    std::cout << "\nПараметры квадрата после умножения его на 2:\n";
//    sq_1.param();
//
//    vec::Vector v{1, 2};
//    std::cout << "\nПараметры квадрата после прибавления вектора v (1, 2):\n";
//    square::Square sq2 = sq_1 + v;
//    sq_1.param();

    square::Square sq1(0, 0, 4, 34);
    square::Square sq2 = 2 * sq1;
    sq1.param();
    sq2.param();
    std::cout << "\n\n\n";
    vec::Vector v{1, 2};
    square::Square sq3(sq1);
    sq3 = sq1 + v;
    sq1.param();
    sq3.param();

    return 0;
}
