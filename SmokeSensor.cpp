#include "SmokeSensor.h"
#include <iostream>

SmokeSensor::SmokeSensor(SensorFlyweight* f)
    : SafetySensor(f) {}

void SmokeSensor::check() {
    if (currentValue > flyweight->threshold) {
        std::cout << "[Дым] Опасно! Превышение: " << currentValue << "\n";
    }
}