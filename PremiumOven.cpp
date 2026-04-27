#include "PremiumOven.h"
#include <iostream>

void PremiumOven::turnOn() {
    isOn = true;
    std::cout << "[Премиум духовка] Включена\n";
}

void PremiumOven::turnOff() {
    isOn = false;
    std::cout << "[Премиум духовка] Выключена\n";
}

std::string PremiumOven::getStatus() {
    if (isOn) {
        return "Премиум духовка: Включена";
    }
    else {
        return "Премиум духовка: Выключена";
    }
}

void PremiumOven::setTemperature(int temp) {
    temperature = temp;
    std::cout << "[Премиум духовка] Установлена температура: " << temperature << "\n";
}

void PremiumOven::selfCleaning() {
    std::cout << "[Премиум духовка] Включена самоотчистка\n";
}

PremiumOven::PremiumOven(HeatingImpl* impl)
    : SmartOven(impl) {}

void PremiumOven::startCooking() {
    if (isOn) {
        heating->heat(temperature);
    }
}