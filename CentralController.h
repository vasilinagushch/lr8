#pragma once
#include "SmartDevice.h"
#include "SafetySensor.h"
#include <vector>

class CentralController {
protected:
    std::vector<SmartDevice*> devices;
    std::vector<SafetySensor*> sensors;

public:
    // --- Добавление устройств ---
    virtual void addDevice(SmartDevice* device) {
        devices.push_back(device);
    }

    // --- Добавление датчиков ---
    virtual void addSensor(SafetySensor* sensor) {
        sensors.push_back(sensor);
    }

    // --- Доступ к данным (для экспертов) ---
    virtual std::vector<SmartDevice*>& getDevices() {
        return devices;
    }

    virtual std::vector<SafetySensor*>& getSensors() {
        return sensors;
    }

    // --- Поведение системы ---
    virtual void runAll() = 0;

    virtual void cookingScenario(SmartDevice* cooktop,
        SmartDevice* hood) = 0;

    // --- Деструктор ---
    virtual ~CentralController() {}
};