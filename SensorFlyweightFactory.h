#pragma once
#include "SensorFlyweight.h"
#include <map>

class SensorFlyweightFactory {
private:
    // Пул для хранения легковесов (по ключу типа и порога срабатывания)
    std::map<std::string, SensorFlyweight*> pool;

public:
    // Метод для получения легковеса, создаёт новый или возвращает существующий
    // type - тип датчика (например, "gas", "smoke", "water")
    // threshold - порог срабатывания для датчика
    SensorFlyweight* getFlyweight(std::string type, double threshold);
};