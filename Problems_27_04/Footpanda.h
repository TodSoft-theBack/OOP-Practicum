#include "Restaurant.h"

class Footpanda
{
    private:
        Restaurant** restaurants = nullptr;
        size_t _count = 0;
        size_t _capacity = 0;

        void CopyMemberData(const Footpanda& copy);
        void MoveMemberData(Footpanda&& temporatry);
	    void FreeMemberData();
        
    public:
        Footpanda(size_t capacity);
        void AddRestaurant(const Restaurant& newRestaurant);
        void AddRestaurant(Restaurant&& newRestaurant);
        void Run();
        ~Footpanda();
};
