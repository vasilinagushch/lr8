#pragma once
#include "CentralController.h"

class KitchenController : public CentralController {
public:
    void runAll() override {
        for (auto d : devices) {
            d->turnOn(); // или что у тебя есть
        }
    }

    void cookingScenario(SmartDevice* cooktop, SmartDevice* hood) override {
        cooktop->turnOn();
        hood->turnOn();
    }
};
