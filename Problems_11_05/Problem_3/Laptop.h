#pragma once
#include "Computer.h"

class Laptop : public Computer
{
    static const unsigned MAX_PERIPHERALS_COUNT = 3;
    static const std::string peripherals[MAX_PERIPHERALS_COUNT];

    public:
        Laptop(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram) ;
        void Type() const override;
        void Peripherals() const override;

};