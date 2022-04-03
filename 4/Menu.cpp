#include "Menu.h"

void Menu::print_menu() {
    cout << "1. Добавить фигуру\n";
    cout << "2. Показать все фигуры\n";
    cout << "3. Сумма площадей фигур\n";
    cout << "4. Сумма периметров фигур\n";
    cout << "5. Центр масс всех фигур\n";
    cout << "6. Память, занимаемая всеми фигурами\n";
    cout << "7. Сортировка фигур\n";
    cout << "8. Выход\n";
    cout << "> ";
}

void Menu::print_fig_menu() {
    cout << "1. Круг\n";
    cout << "2. Прямоугольник\n";
    cout << "> ";
}

int Menu::get_variant() {
    int variant;
    string s; // строка для считывания введённых данных
    cin >> s; // считывание строки
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > 8) {
        cout << "Некорректный ввод. Попробуйте еще раз: "; // выводим сообщение об ошибке
        cin >> s; // повторное считывание строки
    }
    return variant;
}

int Menu::get_fig_variant() {
    int variant;
    string s; // строка для считывания введённых данных
    cin >> s; // считывание строки
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > 2) {
        cout << "Некорректный ввод. Попробуйте еще раз: "; // выводим сообщение об ошибке
        cin >> s; // повторное считывание строки
    }
    return variant;
}

void Menu::reproduction(vector<Figure *> &S) {
    int command;
    unsigned int memory;
    double x, y, sumOfPer, sumOfArea, mass;
    CVector2D massCentre;
    do {
        Menu::print_menu();
        command = Menu::get_variant();
        switch (command) {
            case 1:
                Menu::print_fig_menu();
                command = Menu::get_fig_variant();
                switch (command) {
                    case 1:
                        S.push_back(new Circle());
                        break;
                    case 2:
                        S.push_back(new Rectangle());
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                for (auto figure: S) {
                    figure->draw();
                }
                break;
            case 3:
                sumOfArea = 0;
                for (auto figure: S) {
                    sumOfArea += figure->square();
                }
                cout << "Площадь фигур: " << sumOfArea << "\n\n";
                break;
            case 4:
                sumOfPer = 0;
                for (auto figure: S) {
                    sumOfPer += figure->perimeter();
                }
                cout << "Периметр фигур: " << sumOfPer << "\n\n";
                break;
            case 5:
                mass = 0;
                x = 0;
                y = 0;
                for (auto figure: S) {
                    x += figure->position().x * figure->mass();
                    y += figure->position().y * figure->mass();
                    mass += figure->mass();
                }
                massCentre.x = x / mass;
                massCentre.y = y / mass;
                cout << "Центр масс: " << massCentre << "\n\n";
                break;
            case 6:
                cout << "Память каждой фигур: ";
                memory = 0;
                for (auto figure: S) {
                    cout << figure->size() << " ";
                    memory += figure->size();
                }
                cout << "\nПамять всех фигур: " << memory << "\n\n";
                break;
            case 7:
                sort(S.begin(), S.end(), [](Figure *x, Figure *y) { return *x < *y; });
                cout << "Фигуры в порядке возрастания: ";
                for (auto figure: S) {
                    cout << figure->mass() << " ";
                }
                cout << "\n\n";
                break;
            default:
                break;
        }
        if (command != 8) {
            system("read -n 5 -s -p \"Press any key to continue...\"");
            std::cout << "\n\n\n\n";
        }
    } while (command != 8);
    return;
}

