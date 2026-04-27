#pragma once
#include "SmartHood.h"

class BasicHood : public SmartHood {

public:
    void turnOn() override;
    void turnOff() override;
    std::string getStatus() override;
};