#pragma once

#include "random_iterator.h"

template<typename T>
class CycleBuffer {
private:
    T *container;
    int size = 0;
    int capacity = 0;

    void transfer_container(T *data) {
        container = new T[capacity];
        for (int i = 0; i < size; ++i) {
            container[i] = data[i];
        }
    }

    void shift_left() {
        for (int i = 0; i < size - 1; i++) {
            container[i] = container[i + 1];
        }
    }

    void shift_right() {
        for (int i = size - 1; i >= 1; i--) {
            container[i] = container[i - 1];
        }
    }

    bool empty() {
        if (capacity == 0) {
            return true;
        }
        return false;
    }

public:
    explicit CycleBuffer(int n = 0) {
        change_capacity(n);
    }

    void change_capacity(int n) {
        capacity = n;
        transfer_container(container);
    }

    Iterator<T> begin() {
        return Iterator<T>(container);
    }

    Iterator<T> end() {
        T *end_ = container + size;
        return Iterator<T>(end_);
    }


    void push_back(T value) {
        if (empty()) {
            return;
        }
        if (size != capacity) {
            container[size++] = value;
        } else {
            shift_left();
            container[size - 1] = value;
        }
    }

    bool pop_back() {
        if (empty()) {
            return false;
        }
        size--;
        return true;
    }

    T back() {
        return *(end() - 1);
    }

    void push_front(T value) {
        if (empty()) {
            return;
        }
        if (size != capacity) {
            size++;
        }
        shift_right();
        container[0] = value;
    }

    bool pop_front() {
        if (empty()) {
            return false;
        }
        T tmp = container[0];
        shift_left();
        size--;
        return true;
    }

    T front() {
        return *(begin());

    }

    T &operator[](int i) {
        if (i >= size || i < 0) {
            std::cout << "\n";
            throw std::out_of_range("Error");
        }
        return container[i];
    }
};