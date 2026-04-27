#pragma once
#include "SensorFlyweight.h"

class SafetySensor {
protected:
    // Указатель на объект SensorFlyweight, который содержит общие данные для всех датчиков одного типа
    SensorFlyweight* flyweight;

    // Текущее значение датчика (например, уровень газа, дым или утечка воды)
    double currentValue;

public:
    // Конструктор, который принимает объект SensorFlyweight
    // Этот объект используется для хранения общих данных, таких как тип датчика и порог срабатывания
    SafetySensor(SensorFlyweight* f) : flyweight(f), currentValue(0) {}

    // Метод для установки значения датчика 
    virtual void setValue(double val) {
        currentValue = val;  // Устанавливаем текущее значение датчика
    }

    // Определяет проверку состояния датчика 
    virtual void check() = 0;
};
