#include <iostream>
#include <algorithm>
#include "cycle_buffer.h"

using namespace std;


int main() {

    cout << "Объявление буфера с капасити 2 + добавление в него двух элементов\n";
    CycleBuffer<int> buffer(2);
    buffer.push_back(1);
    buffer.push_back(2);
    cout << "1 2: " << buffer[0] << " " << buffer[1] << "\n\n";

    cout << "Изменение капасити на 3 и добавление одного элемента\n";

    buffer.change_capacity(3);
    buffer.push_back(5);
    cout << "1 2 5: " << buffer[0] << " " << buffer[1] << " " << buffer[2] << "\n\n";

    cout << "2 вывода последнего элемента и 1 вывод первого элемента буфера\n";
    cout << "5 5 1: " << buffer.back() << " " << buffer.back() << " " << buffer.front() << "\n\n";

    cout << "Добавление трех элементов\n";
    buffer.push_back(3);
    buffer.push_back(1);
    buffer.push_back(2);
    cout << "3 1 2: " << buffer[0] << " " << buffer[1] << " " << buffer[2] << "\n\n";

    cout << "Удаление последнего\n";
    buffer.pop_back();
    cout << "3 1: " << buffer[0] << " " << buffer[1] << " " << "\n\n";

    cout << "Добавление в начало\n";
    buffer.push_front(7);
    cout << "7 3 1: " << buffer[0] << " " << buffer[1] << " " << buffer[2] << "\n\n";

    cout << "Сортировка буфера (изначальный буфер = [7, 3, 1])\n";
    sort(buffer.begin(), buffer.end());
    cout << "1 3 7: " << buffer[0] << " " << buffer[1] << " " << buffer[2] << "\n\n";

    cout << "Проверка алгоритма: partition\n";
    CycleBuffer<int> arr(10);
    for (int i = 0; i < 10; i++) {
        arr.push_back(i);
    }
    cout << "Изначальный буфер: ";
    for (auto c: arr) {
        cout << c << " ";
    }
    cout << '\n';

    partition(arr.begin(), arr.end(), [](int i) { return i % 2 == 0; });
    cout << "После применения partition: ";

    for (auto c: arr) {
        cout << c << " ";
    }
    cout << '\n';
    return 0;
}
