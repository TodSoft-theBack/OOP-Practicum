#include "CarPart.h"

class Engine : public CarPart
{
    private:
        unsigned horsepower;

    public:
        Engine(std::string manufacturer, std::string description, unsigned horsepower);
        friend std::ostream& operator<<(std::ostream& output, const Engine& engine); 
};
