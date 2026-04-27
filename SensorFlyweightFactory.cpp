#include "SensorFlyweightFactory.h"
#include <iostream>
#include <iomanip>

SensorFlyweight* SensorFlyweightFactory::getFlyweight(std::string type, double threshold) {
    // Создаем уникальный ключ для каждого типа и порога срабатывания
    std::string key = type + "_" + std::to_string(threshold);

    // Проверка наличия уже существующего легковеса
    if (pool.find(key) == pool.end()) {
        pool[key] = new SensorFlyweight(type, threshold);
        std::cout << "[ЛЕГКОВЕС] Создание нового легковеса: " << type << "_" << std::fixed << std::setprecision(2) << threshold
            << " (адрес: " << pool[key] << ")" << std::endl;  // Выводим адрес создаваемого объекта
    }
    else {
        std::cout << "[ЛЕГКОВЕС] Использование существующего легковеса: " << type << "_" << std::fixed << std::setprecision(2) << threshold
            << " (адрес: " << pool[key] << ")" << std::endl;  // Выводим адрес существующего объекта
    }

    return pool[key];
}