#include "CarPart.h"

unsigned long CarPart::FIRST_FREE_ID = 1;

CarPart::CarPart(std::string manufacturer, std::string description) : _manufacturer(manufacturer), _description(description)
{
    id = FIRST_FREE_ID++;
}

std::ostream& operator<<(std::ostream& output, const CarPart& part)
{
    return output << "("<< part.id <<") by " << part._manufacturer <<" – " << part._description << std::endl;
}