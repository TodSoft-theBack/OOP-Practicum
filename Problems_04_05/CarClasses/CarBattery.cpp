#include "CarBattery.h"

CarBattery::CarBattery(unsigned capacity, std::string batteryID, std::string manufacturer, std::string description) : CarPart(manufacturer, description),_capacity(capacity), _batteryID(batteryID)
{

}

std::ostream& operator<<(std::ostream& output, const CarBattery& battery)
{
    return output << (CarPart)battery << " – " << battery._capacity <<" Ah" << std::endl;
}