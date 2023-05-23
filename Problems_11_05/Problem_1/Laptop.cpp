#include "Laptop.h"

const std::string Laptop::peripherals[MAX_PERIPHERALS_COUNT] = {"Mouse pad", "Keyboard", "Monitor"};

Laptop::Laptop(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram) : Computer(processor, graphicsUnit, powerSupply, ram) { }

void Laptop::Type() const 
{
    std::cout << "Laptop" << std::endl;
}

void Laptop::Peripherals() const 
{
    for (size_t i = 0; i < MAX_PERIPHERALS_COUNT; i++)
        std::cout << peripherals[i] << std::endl;
}