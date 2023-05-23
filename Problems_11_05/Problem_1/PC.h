#pragma once
#include "Computer.h"

class PC : public Computer
{
    static const unsigned MAX_PERIPHERALS_COUNT = 4;
    static const std::string peripherals[MAX_PERIPHERALS_COUNT];
    public:
        PC(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram) ;
        void Type() const override;
        void Peripherals() const override;
};