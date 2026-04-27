#include "GasSensor.h"
#include <iostream>

GasSensor::GasSensor(SensorFlyweight* f)
    : SafetySensor(f) {}

void GasSensor::check() {
    if (currentValue > flyweight->threshold) {
        std::cout << "[ГАЗ] Опасно! Превышение: " << currentValue << "\n";
    }
}