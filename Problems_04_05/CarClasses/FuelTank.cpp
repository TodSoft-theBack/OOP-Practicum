#include "FuelTank.h"
#include "insufficient_fuel_error.h"

FuelTank::FuelTank(size_t capacity) : _capacity(capacity), _volume(capacity) { }

void FuelTank::UseFuel(size_t amount)
{
    if (_volume - amount < 0)
        throw insufficient_fuel_error();
    _volume -= amount;
    
}

void FuelTank::LoadFuel(size_t amount)
{
    _volume += amount;
}