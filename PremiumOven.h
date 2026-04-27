#pragma once
#include "SmartOven.h"

class PremiumOven : public SmartOven {
private:
    bool isOn;
public:

    PremiumOven(HeatingImpl* impl);

    void turnOn() override;
    void turnOff() override;
    std::string getStatus() override;
    void selfCleaning();
    void setTemperature(int temp) override;
    void startCooking() override;
};