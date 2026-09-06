#pragma once

#include <string>

class Table {
public:
    virtual void set(std::string value) = 0;
    virtual std::string get(int key) = 0;
    virtual bool exists(int key) = 0;

};