#include <iostream>
#include <vector>
#include "iter.h"
#include <array>

using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    cout << it::any_of(v, [](int num) { return num == 1; }) << endl;
    cout << it::find_not(v, 0, it::find_not_predicator<int>) << endl;

    cout.setf(std::ios_base::boolalpha);
    cout << it::is_partitioned(v, it::is_even<int>) << " ";
    for (auto c: v) {
        cout << c << " ";
    }
    cout << endl;

    partition(v.begin(), v.end(), [](int i) { return i % 2 == 0; });
    cout << it::is_partitioned(v, it::is_even<int>) << ' ';
    for (auto c: v) {
        cout << c << " ";
    }
    cout << endl;


    return 0;
}
