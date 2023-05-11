#include <iostream>

class FuelTank
{
    private:
        size_t _capacity;
        size_t _volume;

    public:
        FuelTank(size_t capacity);
        void UseFuel(size_t amount);
        void LoadFuel(size_t amount);
};
