#pragma once
#include "IInfoExpert.h"
#include "CentralController.h"

class DeviceListExpert : public IInfoExpert {
private:
    CentralController* controller;

public:
    DeviceListExpert(CentralController* c) : controller(c) {}

    double getValue() override {
        return controller->getDevices().size();
    }

    std::string getReport() override {
        std::string report = "Устройства:\n";

        for (auto d : controller->getDevices()) {
            report += d->getStatus() + "\n";
        }

        return report;
    }
};
