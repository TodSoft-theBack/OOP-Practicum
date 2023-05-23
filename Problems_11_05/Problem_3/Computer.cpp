#include "Computer.h"

void Computer::SetCPU(double clockSpeed)
{
    this->clockSpeed = clockSpeed;
}

void Computer::SetGPU(std::string graphicsCards)
{
    this->graphicsCards = graphicsCards;
}

void Computer::SetPS (unsigned powerSupply)
{
    this->powerSupply = powerSupply;
}

void Computer::SetRAM(unsigned ram)
{
    this->ram = ram;
}

double Computer::CPU() const
{
    return clockSpeed;
}

std::string Computer::GPU() const
{
    return graphicsCards;
}

unsigned Computer::PS() const
{
    return powerSupply;
}

unsigned Computer::RAM() const
{
    return ram;
}

Computer::Computer(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram)
{
    SetCPU(processor);
    SetGPU(graphicsUnit);
    SetPS(powerSupply);
    SetRAM(ram);
}