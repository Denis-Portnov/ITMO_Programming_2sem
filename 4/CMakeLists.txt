cmake_minimum_required(VERSION 3.20)
project(4)

set(CMAKE_CXX_STANDARD 14)

add_executable(4 main.cpp IGeoFig.h CVector2D.h IPhysObject.h
        IPrintable.h IDialogInitiable.h BaseCObject.h Figure.cpp Figure.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h Menu.cpp Menu.h)
