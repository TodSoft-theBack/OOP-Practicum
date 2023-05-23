#include "PC.h"

const std::string PC::peripherals[MAX_PERIPHERALS_COUNT] = {"Mouse", "Keyboard", "Microphone", "Headphones"};

PC::PC(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram) : Computer(processor, graphicsUnit, powerSupply, ram) { }

void PC::Type() const 
{
    std::cout << "PC" << std::endl;
}

void PC::Peripherals() const 
{
    for (size_t i = 0; i < MAX_PERIPHERALS_COUNT; i++)
        std::cout << peripherals[i] << std::endl;
}