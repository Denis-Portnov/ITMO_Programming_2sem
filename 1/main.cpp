#include <iostream>
#include "fun.h"

using namespace std;


int main() {
    float x1, x2;
    cin >> x1 >> x2;

    cout << "Первое введенное число для отбрасывания дробной части = " << x1 << '\n';
    fun::whole_1(&x1);
    cout << "Первое введенное число после отбрасывания дробной части с помощью указателя = " << x1 << '\n';

    cout << '\n' << "Второе введенное число для отбрасывания дробной части = " << x2 << '\n';
    fun::whole_2(x2);
    cout << "Второе введенное число после отбрасывания дробной части с помощью ссылки = " << x2 << '\n';


    int y1, y2;
    cin >> y1 >> y2;
    cout << "Первое целое число для измены знака = " << y1 << '\n';
    fun::change_i1(&y1);
    cout << "Первое целое число после измены знака с помощью указателя = " << y1 << '\n';

    cout << '\n' << "Второе целое число для измены знака = " << y2 << '\n';
    fun::change_i2(y2);
    cout << "Второе целое число после измены знака с помощью ссылки = " << y2 << '\n';

    float z1, z2;
    cin >> z1 >> z2;
    cout << "Первое вещественное число для измены знака = " << z1 << '\n';
    fun::change_f1(&z1);
    cout << "Первое вещественное число после измены знака с помощью указателя = " << z1 << '\n';

    cout << '\n' << "Второе вещественное число для измены знака = " << z2 << '\n';
    fun::change_f2(z2);
    cout << "Второе вещественное число после измены знака с помощью ссылки = " << z2 << '\n';
    float arr[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    float *p = &arr[0][0];
    fun::matrix_1(p, 5.5);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    fun::matrix_2(arr, 5.5);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    float x0, y0;
    cin >> x0 >> y0;
    fun::Circle circle{x0, y0};
    fun::Vector vector{1, 1};
    fun::Circle *с;
    fun::Vector *v;
    с = &circle;
    v = &vector;
    cout << circle.x0 << ' ' << circle.y0 << '\n';
    fun::move_1(с, v);
    cout << circle.x0 << ' ' << circle.y0 << '\n';
    fun::move_2(circle, vector);
    cout << circle.x0 << ' ' << circle.y0 << '\n';

    return 0;
}
