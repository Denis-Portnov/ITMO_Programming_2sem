#pragma once

class BaseCObject {
public:
    virtual const char *className() = 0;

    virtual unsigned int size() = 0;
};