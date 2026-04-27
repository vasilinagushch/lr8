#pragma once
#include "SmartDevice.h"
#include <iostream>

class DeviceProxy : public SmartDevice {
private:
    SmartDevice* device;
    bool isBlocked = false;

public:
    DeviceProxy(SmartDevice* dev) : device(dev) {}

    void turnOn() override {
        std::cout << "[Прокси] Проверка доступа...\n";
        if (isBlocked) {
            std::cout << "[Прокси] Доступ запрещён!\n";
            return;
        }
        std::cout << "[Прокси] Доступ разрешён\n";
        device->turnOn();
    }

    void turnOff() override {
        device->turnOff();
    }

    std::string getStatus() override {
        return device->getStatus();
    }
};