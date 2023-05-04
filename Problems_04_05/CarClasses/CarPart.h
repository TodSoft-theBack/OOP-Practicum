#include <iostream>
#include <cstring>

class CarPart
{
    static unsigned long FIRST_FREE_ID;
    private:
        unsigned long id;
        std::string _manufacturer;
        std::string _description;
    public:
        CarPart(std::string manufacturer, std::string description);
        friend std::ostream& operator<<(std::ostream& output, const CarPart& part); 
};


