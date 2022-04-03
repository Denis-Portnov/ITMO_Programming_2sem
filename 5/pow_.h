#pragma once

#include <iostream>
#include <string>

class IsNotCorrectValue : public std::logic_error {
public:
    explicit IsNotCorrectValue(const std::string &str) :
            std::logic_error(str) {}
};


namespace pow_ {
    template<typename T_num, typename T_degree>
    T_num pow_(T_num num, T_degree degree) {
        try {
            if (typeid(degree) != typeid(int)) throw IsNotCorrectValue("Degree is not an int");
            if (degree == 0) {
                return 1;
            }

            int i = 1, tmp = num;
            while (i < abs(degree)) {
                num *= tmp;
                i++;
            }
            if (degree > 0) {
                return num;
            } else if (degree < 0) {
                return 1 / num;
            }
        }
        catch (IsNotCorrectValue &e) {
            std::cout << e.what() << "\n";
        }
    }
}
