#include "SilentHood.h"
#include <iostream>

SilentHood::SilentHood()
    : SmartHood("Вытяжка с пониженным шумом", 300) {}

void SilentHood::noiseReductionMode() {
    std::cout << "[Вытяжка с пониженным шумом] Снижение шума включено\n";
}

void SilentHood::turnOn() {
    isOn = true;
    std::cout << "[Вытяжка с пониженным шумом] Включена\n";
}

void SilentHood::turnOff() {
    isOn = false;
    std::cout << "[Вытяжка с пониженным шумом] Выключена\n";
}

std::string SilentHood::getStatus() {
    if (isOn) {
        return "Вытяжка с пониженным шумом: Включена";
    }
    else {
        return "Вытяжка с пониженным шумом: Выключена";
    }
}
