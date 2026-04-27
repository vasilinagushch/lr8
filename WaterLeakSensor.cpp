#include "WaterLeakSensor.h"
#include <iostream>

WaterLeakSensor::WaterLeakSensor(SensorFlyweight* f)
    : SafetySensor(f) {}

void WaterLeakSensor::check() {
    if (currentValue > flyweight->threshold) {
        std::cout << "[Протечка] Опасно! Превышение: " << currentValue << "\n";
    }
}