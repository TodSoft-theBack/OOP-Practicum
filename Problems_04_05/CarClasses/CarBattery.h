#include "CarPart.h"

class CarBattery : CarPart
{
    private:
        unsigned _capacity;
        std::string _batteryID; 

    public:
        CarBattery(unsigned _capacity, std::string _batteryID, std::string manufacturer, std::string description);
        friend std::ostream& operator<<(std::ostream& output, const CarBattery& battery); 
};