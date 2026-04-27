#pragma once
#include "IInfoExpert.h"
#include "CentralController.h"

class PowerConsumptionExpert : public IInfoExpert {
private:
    CentralController* controller;

public:
    PowerConsumptionExpert(CentralController* c);
    double getValue() override;
    std::string getReport() override;
};
