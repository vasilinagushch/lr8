#pragma once
#include "SafetySensor.h"

class GasSensor : public SafetySensor {
public:
    GasSensor(SensorFlyweight* f);
    void check() override;
};