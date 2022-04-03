#pragma once

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

class Menu {
public:
    static void print_menu();

    static void print_fig_menu();

    static int get_variant();

    static int get_fig_variant();

    static void reproduction(vector<Figure *> &S);

};

