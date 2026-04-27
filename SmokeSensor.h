#pragma once
#include "SafetySensor.h"

class SmokeSensor : public SafetySensor {
public:
    SmokeSensor(SensorFlyweight* f);
    void check() override;
};
