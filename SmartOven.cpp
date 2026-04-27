#include "SmartOven.h"

SmartOven::SmartOven(HeatingImpl* impl)
    : SmartDevice(name, 1800), heating(impl), temperature(0) {}

void SmartOven::turnOn() {
    isOn = true;
}

void SmartOven::turnOff() {
    isOn = false;
    heating->cool();  
}

std::string SmartOven::getStatus() {
    return isOn ? "ON" : "OFF";
}

void SmartOven::setTemperature(int temp) {
    temperature = temp;
}