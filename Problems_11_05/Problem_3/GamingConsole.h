#pragma once
#include "Computer.h"

class GamingConsole : public Computer
{
    static const unsigned MAX_PERIPHERALS_COUNT = 2;
    static const std::string peripherals[MAX_PERIPHERALS_COUNT];

    public:
        GamingConsole(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram) ;
        void Type() const override;
        void Peripherals() const override;
};