#include "CentralController.h"
#include "DeviceProxy.h"
#include "SmartOven.h"
#include "BasicOven.h"
#include "PremiumOven.h"
#include "SmartRefrigerator.h"
#include "BasicRefrigerator.h"
#include "PremiumRefrigerator.h"
#include "SmartCooktop.h"
#include "GasCooktop.h"
#include "InductionCooktop.h"
#include "SmartHood.h"
#include "BasicHood.h"
#include "SilentHood.h"
#include "SmartDishwasher.h"
#include "CompactDishwasher.h"
#include "FullSizeDishwasher.h"
#include "RecipeManager.h"
#include "SensorFlyweightFactory.h"
#include "GasSensor.h"
#include "SmokeSensor.h"
#include "WaterLeakSensor.h"
#include "KitchenFacade.h"
#include "PowerConsumptionExpert.h"
#include "DeviceListExpert.h"
#include "KitchenController.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "rus");



    // BRIDGE

    // Улучшеная демонстрация: Базовая духовка + Газовый нагрев, Базовая духовка + Электрический нагрев, 
    // Премиум духовка + Газовый нагрев, Премиум духовка + Электрический нагрев
    HeatingImpl* heatingG = new GasHeating();
    SmartOven* basicOvenG = new BasicOven(heatingG); // Базовая духовка + Газовый нагрев

    HeatingImpl* heatingE = new ElectricHeating();
    SmartOven* premiumOvenE = new PremiumOven(heatingE); // Премиум духовка + Электрический нагрев

    SmartOven* basicOvenE = new BasicOven(heatingE); // Базовая духовка + Электрический нагрев
    SmartOven* premiumOvenG = new PremiumOven(heatingG); // Премиум духовка + Газовый нагрев

    cout << "[Базовая духовка + Газовый нагрев] статус до готовки: " << basicOvenG->getStatus() << std::endl;
    basicOvenG->turnOn();
    basicOvenG->setTemperature(200);
    basicOvenG->startCooking();
    basicOvenG->turnOff();
    cout << "[Базовая духовка + Газовый нагрев] статус после готовки: " << basicOvenG->getStatus() << std::endl;

    cout << "\n[Базовая духовка + Электрический нагрев] статус до готовки: " << basicOvenE->getStatus() << std::endl;
    basicOvenE->turnOn();
    basicOvenE->setTemperature(180);
    basicOvenE->startCooking();
    basicOvenE->turnOff();
    cout << "[Базовая духовка + Электрический нагрев] статус после готовки: " << basicOvenE->getStatus() << std::endl;

    cout << "\n[Премиум духовка + Газовый нагрев] статус до готовки: " << premiumOvenG->getStatus() << std::endl;
    premiumOvenG->turnOn();
    premiumOvenG->setTemperature(200);
    premiumOvenG->startCooking();
    premiumOvenG->turnOff();
    cout << "[Премиум духовка + Газовый нагрев] статус после готовки: " << premiumOvenG->getStatus() << std::endl;

    cout << "\n[Премиум духовка + Электрический нагрев] статус до готовки: " << premiumOvenE->getStatus() << std::endl;
    premiumOvenE->turnOn();
    premiumOvenE->setTemperature(180);
    premiumOvenE->startCooking();
    premiumOvenE->turnOff();
    cout << "[Премиум духовка + Электрический нагрев] статус после готовки: " << premiumOvenE->getStatus() << std::endl;
    cout << endl;

    // FLYWEIGHT


    SensorFlyweightFactory factory;

    // создаём легковесы
    auto gasFly = factory.getFlyweight("gas", 5.0);
    auto gasFly1 = factory.getFlyweight("gas", 5.0);

    auto smokeFly = factory.getFlyweight("smoke", 300.0);
    auto waterFly = factory.getFlyweight("water", 10.0);

    // Выводим адреса объектов для проверки, что это один и тот же объект
    std::cout << "Адрес gasFly: " << gasFly << std::endl;
    std::cout << "Адрес gasFly1: " << gasFly1 << std::endl;

    // создаём датчики
    GasSensor gas(gasFly);
    SmokeSensor smoke(smokeFly);
    WaterLeakSensor water(waterFly);

    // задаём значения
    gas.setValue(6.0);
    smoke.setValue(350.0);
    water.setValue(5.0);

    // проверка
    gas.check();
    smoke.check();
    water.check();



    // FACADE

    KitchenController controller;

    KitchenFacade facade(&controller);
    facade.initializeDevices();  // Инициализация и добавление устройств в контроллер

    facade.cookDish();  // Начинаем готовить

    facade.checkAllSensors();  // Проверяем все датчики безопасности

    //facade.emergencyStop();  // Останавливаем все устройства



    // INFORMATION EXPERT

    // Улучшенная демонстрация, создание при помощи родительского класса:
    IInfoExpert* devicelistexpert = new DeviceListExpert(&controller);
    IInfoExpert* powerconsumptionexpert = new PowerConsumptionExpert(&controller);

    DeviceListExpert deviceExpert(&controller);
    PowerConsumptionExpert powerExpert(&controller);

    // Получение количества устройств
    cout << "[ЭКСПЕРТ] Общее количество устройств: " << deviceExpert.getValue() << std::endl;

    // Получение отчета о устройствах
    cout << deviceExpert.getReport() << std::endl;

    // Получение информации о потреблении энергии
    cout << "[ЭКСПЕРТ] Общее энергопотребление: " << powerExpert.getValue() << " Вт" << std::endl;

    // Получение отчета о потреблении энергии
    cout << powerExpert.getReport() << std::endl;


    // Освобождение памяти
    delete basicOvenE;

    return 0;
}