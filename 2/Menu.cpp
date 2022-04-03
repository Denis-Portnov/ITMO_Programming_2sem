
#include "Menu.h"


void Menu::print_menu() {
    std::cout << "Что необходимо сделать со стеком?" << '\n';
    std::cout << "1. Добавить элемент в стек" << '\n';
    std::cout << "2. Изъять последний элемент" << '\n';
    std::cout << "3. Узнать количество элементов в стеке" << '\n';
    std::cout << "4. Проверить стек на пустоту" << '\n';
    std::cout << "5. Просмотреть верхний элемент" << '\n';
    std::cout << "6. Вывести содержимое стека на экран" << '\n';
    std::cout << "7. Выход" << '\n';
    std::cout << "> ";
}

int Menu::get_variant() {
    int variant;
    std::string s; // строка для считывания введённых данных
    std::cin >> s; // считывание строки
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > 7) {
        std::cout << "Некорректный ввод. Попробуйте еще раз: "; // выводим сообщение об ошибке
        std::cin >> s; // повторное считывание строки
    }
    return variant;
}


void Menu::reproduction(Stack &S) {
    int x, y, var;
    do {
        Menu::print_menu();
        var = Menu::get_variant();
        switch (var) {
            case 1:
                std::cout << "Введите число для добавления в стек: ";
                std::cin >> x;
                if (S.push(x)) std::cout << "В стек успешно добавлен элемент: " << x << '\n';
                else
                    std::cout << "Извините, стек заполнен => элемент не добавлен, "
                                 "и последующие попытки добавления элемента будут бессмысленны\n";
                break;
            case 2:
                y = S.pop();
                if (y != INT32_MIN) std::cout << "Извлеченный элемент: " << y << '\n';
                else std::cout << "УПС, стек пуст, извлекать нечего(\n";
                break;
            case 3:
                std::cout << "Размер стека: " << S.size() << '\n';
                break;
            case 4:
                if (S.is_empty()) std::cout << "Стек пуст\n";
                else std::cout << "В стеке присутствуют элементы\n";
                break;
            case 5:
                if (S.top() != INT32_MIN)std::cout << "Верхний элемент стека: " << S.top() << '\n';
                else std::cout << "Стек пуст:)\n";
                break;
            case 6:
                S.print();
                break;
        }
        if (var != 7) {
            system("read -n 5 -s -p \"Press any key to continue...\"");
            std::cout << "\n\n\n\n";
        }
    } while (var != 7);
}








