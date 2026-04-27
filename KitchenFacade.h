#pragma once
#include "CentralController.h"

class KitchenFacade {
private:
    CentralController* controller;

public:
    KitchenFacade(CentralController* c);

    void initializeDevices();
    void cookDish();
    void checkAllSensors();
    void emergencyStop();
};