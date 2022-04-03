#include "Stack.h"


bool Stack::push(int x) {
    if (s.size() < H) {
        s.push_back(x);
        return true;
    }
    return false;
}

int Stack::pop() {
    if (!s.empty()) {
        int x = s.back();
        s.pop_back();
        return x;
    }
    return INT32_MIN;
}

int Stack::size() { return s.size(); }

bool Stack::is_empty() {
    if (s.empty()) return true;
    return false;
}

int Stack::top() {
    if (!s.empty()) return s.back();
    return INT32_MIN;
}

void Stack::print() {
    if (!s.empty()) {
        std::cout << "Содержимое стека: ";
        for (auto item: s) {
            std::cout << item << ' ';
        }
        std::cout << '\n';
    } else std::cout << "Стек пуст:)\n";
}

std::ostream &operator<<(std::ostream &out, const Stack &S) {
    out << "Содержимое стека: ";
    for (auto item: S.s) {
        out << item << ' ';
    }
    out << "\nМаксимальная глубина стека = " << S.H << '\n';
    return out;
}


