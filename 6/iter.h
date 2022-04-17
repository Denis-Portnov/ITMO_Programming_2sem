#pragma once

#include <iterator>
#include <iostream>

using namespace std;
namespace it {
    template<class T, class Predicate>
    bool any_of(T obj, Predicate p) {
        typename T::const_iterator it = obj.begin();
        while (it != obj.end()) {
            if (p(*it)) {
                return true;
            }
            it++;
        }
        return false;
    }

    template<class T>
    bool is_even(T x, int num) {
        return x % num == 0;
    }

    template<class T, class Predicate>
    bool is_partitioned(T obj, Predicate p) {
        typename T::const_iterator it = obj.begin();
        for (; it != obj.end(); ++it)
            if (!p(*it, 2)) {
                break;
            }
        for (; it != obj.end(); ++it)
            if (p(*it, 2))
                return false;
        return true;
    }


    template<class T>
    bool find_not_predicator(T x, T y) {
        return x != y;
    }

    template<class T, class P, class U>
    P find_not(T obj, P p, bool(*compare)(U o1, U o2)) {
        int index = -1;
        for (typename T::const_iterator it = obj.begin(); it != obj.end(); it++) {
            index++;
            if (compare(p, *it)) {
                return index;
            }
        }
        return -1;
    }
}