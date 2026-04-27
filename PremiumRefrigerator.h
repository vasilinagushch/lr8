#pragma once
#include "SmartRefrigerator.h"

class PremiumRefrigerator : public SmartRefrigerator {
public:
    void turnOn() override;
    void turnOff() override;
    std::string getStatus() override;
    void checkProducts() override;
    void analyzeFreshness();
    void suggestRecipes();
};