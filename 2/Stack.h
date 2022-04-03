#pragma once

#include <iostream>
#include <vector>


class Stack {
private:
    std::vector<int> s;
    int H;

public:
    Stack() {
        H = 10;
    }

    Stack(int H) {
        this->H = H;
    }

    Stack(const Stack &stack) {
        s = stack.s;
        H = stack.H;
    }

    bool push(int x);

    int pop();

    int size();

    bool is_empty();

    int top();

    void print();

    friend std::ostream &operator<<(std::ostream &out, const Stack &s);


};