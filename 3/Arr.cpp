#include "Arr.h"

namespace arr {
    void Arr::Arr_Cin() const {
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
    }

    void Arr::Arr_Cout() const {
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }

    Arr operator+(const Arr &a, const Arr &b) {
        int s = a.n + b.n;
        int *c = new int[s];
        for (int i = 0; i < a.n; i++) c[i] = a.arr[i];
        for (int i = 0; i < b.n; i++) c[i + a.n] = b.arr[i];
        return Arr(c, s);
    }

    bool operator==(const Arr &a, const Arr &b) {
        return (a.n == b.n);
    }

    bool operator>(const Arr &a, const Arr &b) {
        return (a.n > b.n);
    }

    bool operator<(const Arr &a, const Arr &b) {
        return (a.n < b.n);
    }

    bool operator!=(const Arr &a, const Arr &b) {
        return !(a.n == b.n);
    }
}