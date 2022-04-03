#pragma once

#include <iostream>

namespace arr {
    class Arr {
    private:

    public:
        int *arr;
        int n;

        Arr() {}

        Arr(int x) {
            arr = new int[x];
            n = x;
        }

        Arr(int *a, int x) {
            arr = a;
            n = x;
        }

        void Arr_Cin() const;

        void Arr_Cout() const;

        friend Arr operator+(const Arr &a, const Arr &b);

        friend bool operator==(const Arr &a, const Arr &b);

        friend bool operator>(const Arr &a, const Arr &b);

        friend bool operator<(const Arr &a, const Arr &b);

        friend bool operator!=(const Arr &a, const Arr &b);
    };
}