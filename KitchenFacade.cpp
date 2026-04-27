#include "KitchenFacade.h"
#include "BasicRefrigerator.h"
#include "GasCooktop.h"
#include "SilentHood.h"
#include "FullSizeDishwasher.h"
#include "CentralController.h"
#include <iostream>

KitchenFacade::KitchenFacade(CentralController* c)
    : controller(c) {}

void KitchenFacade::initializeDevices() {
    // Создание устройств
    SmartDevice* basicFridge = new BasicRefrigerator();
    SmartDevice* silentHood = new SilentHood();
    SmartDevice* fullDishwasher = new FullSizeDishwasher();
    SmartDevice* gasCooktop = new GasCooktop();

    // Добавление устройств в контроллер
    controller->addDevice(basicFridge);
    controller->addDevice(silentHood);
    controller->addDevice(fullDishwasher);
    controller->addDevice(gasCooktop);
}

void KitchenFacade::cookDish() {
    // Включаем все устройства
    for (auto d : controller->getDevices()) {
        d->turnOn();
    }
    std::cout << "[ФАСАД] Начало готовки.\n";
}

void KitchenFacade::checkAllSensors() {
    // Проверка всех датчиков
    for (auto s : controller->getSensors()) {
        s->check();
        std::cout << "[ФАСАД] Проверка всех датчиков: всё в порядке.\n";
    }
}

void KitchenFacade::emergencyStop() {
    // Остановка всех устройств
    for (auto d : controller->getDevices()) {
        d->turnOff();
    }
    std::cout << "[ФАСАД] Все устройства выключены!\n";
}