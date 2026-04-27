#pragma once
#include <string>

class IInfoExpert {
public:
    virtual double getValue() = 0;
    virtual std::string getReport() = 0;
};
