#pragma once
#include <iostream>

class HeatingImpl {
public:
    virtual void heat(int temp) = 0;
    virtual void cool() = 0;
    virtual ~HeatingImpl() {}
};

class ElectricHeating : public HeatingImpl {
public:
    void heat(int temp) override {
        std::cout << "[Электрический нагрев] До " << temp << " градусов.\n";
    }

    void cool() override {
        std::cout << "[Электрический нагрев] Охлаждение (выключение нагрева).\n";
    }
};

class GasHeating : public HeatingImpl {
public:
    void heat(int temp) override {
        std::cout << "[Газовый нагрев] До " << temp << " градусов.\n";
    }

    void cool() override {
        std::cout << "[Газовый нагрев] Охлаждение (уменьшение подачи газа).\n";
    }
};
