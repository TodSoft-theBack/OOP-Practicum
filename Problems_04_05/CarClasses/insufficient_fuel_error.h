#include <iostream>

class insufficient_fuel_error : std::logic_error
{
    public:
        insufficient_fuel_error() : logic_error("Insufficient fuel!!!") { };
};