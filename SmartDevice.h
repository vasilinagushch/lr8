#pragma once
#include <string>

class SmartDevice {
protected:
    std::string name;
    int power;
    bool isOn;

public:
    SmartDevice(std::string name = "Unknown", int power = 0, bool isOn = false)
        : name(name), power(power), isOn(isOn) {}

    bool isDeviceOn() const {
        return isOn;
    }

    int getPower() const {
        return power;
    }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getStatus() = 0;          

    virtual ~SmartDevice() {}
};