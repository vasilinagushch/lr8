#pragma once
#include "SafetySensor.h"

class WaterLeakSensor : public SafetySensor {
public:
    WaterLeakSensor(SensorFlyweight* f);
    void check() override;
};
