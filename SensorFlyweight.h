#pragma once
#include <string>

class SensorFlyweight {
public:
    std::string type; // тип датчика
    double threshold; // порог срабатывани€

    // конструктор
    SensorFlyweight(std::string t, double th);
};
