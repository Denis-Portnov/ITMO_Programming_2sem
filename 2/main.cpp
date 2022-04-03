#include <iostream>
#include "Menu.h"
#include <cstdlib>


int main() {
    std::cout << "Введите размерность стека: ";
    int x;
    std::cin >> x;
    Stack S(x);
    Menu::reproduction(S);
    return 0;
}
