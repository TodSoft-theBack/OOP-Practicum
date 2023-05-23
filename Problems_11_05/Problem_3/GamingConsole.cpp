#include "GamingConsole.h"

const std::string GamingConsole::peripherals[MAX_PERIPHERALS_COUNT] = {"Joystick", "Monitor"};

GamingConsole::GamingConsole(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram) : Computer(processor, graphicsUnit, powerSupply, ram) { }

void GamingConsole::Type() const 
{
    std::cout << "Gaming console" << std::endl;
}

void GamingConsole::Peripherals() const 
{
    for (size_t i = 0; i < MAX_PERIPHERALS_COUNT; i++)
        std::cout << peripherals[i] << std::endl;
}