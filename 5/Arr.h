#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<int N, int M, class T>
class Arr {
private:
    vector<vector<T>> array;
public:
    Arr(){
        array = vector<vector<T>>(N, vector<T>(M));
    };

//    Arr(int n, int m) {
//        array = vector<vector<T>>(n, vector<T>(m));
//        this->n = n;
//        this->m = m;
//    }

    void setArr(T object, int i, int j) {
        try {
            if (((i >= N) || (i < 0)) || ((j >= M) || (j < 0)))
                throw logic_error("IndexError: list index out of range");
            array[i][j] = object;
        }
        catch (logic_error &e) {
            cout << e.what() << " in logic_error catch\n";
        }
        catch (exception &e) {
            cout << e.what() << " in exception catch\n";
        }
    }

    T getArr(int i, int j) {
        try {
            if (((i >= N) || (i < 0)) || ((j >= M) || (j < 0)))
                throw out_of_range("IndexError: list index out of range");
            return array[i][j];
        }
        catch (out_of_range &e) {
            cout << e.what() << '\n';
        }
    }

};


