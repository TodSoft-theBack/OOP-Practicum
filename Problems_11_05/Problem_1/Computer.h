#pragma once
#include <iostream>
#include <cstring>

class Computer
{
    private:
        double clockSpeed = 0;
        std::string graphicsCards;
        unsigned powerSupply = 0;
        unsigned ram = 0;

        void SetCPU(double clockSpeed);
        void SetGPU(std::string graphicsCards);
        void SetPS (unsigned powerSupply);
        void SetRAM(unsigned ram);

        double CPU() const;
        std::string GPU() const;
        unsigned PS () const;
        unsigned RAM() const;

    public:
        Computer(double processor, const char* graphicsUnit, unsigned powerSupply, unsigned ram);
        virtual void Type() const = 0;
        virtual void Peripherals() const = 0;
        virtual ~Computer() = default;
};
