#include "PowerConsumptionExpert.h"

PowerConsumptionExpert::PowerConsumptionExpert(CentralController* c)
    : controller(c) {}

double PowerConsumptionExpert::getValue() {
    double sum = 0;

    for (auto d : controller->getDevices()) {
        if (d->isDeviceOn()) {
            sum += d->getPower();
        }
    }

    return sum;
}

std::string PowerConsumptionExpert::getReport() { return std::to_string(getValue()); }