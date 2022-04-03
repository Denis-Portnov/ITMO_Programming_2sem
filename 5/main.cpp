#include <iostream>
#include "pow_.h"
#include "Arr.h"

using namespace std;

int main() {


    int x = pow_::pow_(3, 2);
    cout << x << '\n';
    int y = pow_::pow_(1, 0.5);


    Arr<5, 5, int> arr;
    arr.setArr(5, 1, 5);
    arr.setArr(5, 1, 4);
    int a = arr.getArr(1, 4);
    cout << a << '\n';
    int b = arr.getArr(3, 5);


    return 0;
}
