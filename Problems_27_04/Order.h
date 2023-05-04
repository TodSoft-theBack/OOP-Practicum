#pragma once
#include "Restaurant.h"
#include "MiString.h"


class Order
{
    private:
        char restaurantName[Restaurant::RESTRAURANT_NAME_SIZE];
        MiString* products;
        size_t count;

        void CopyMemberData(const Order& copy);
        void MoveMemberData(Order&& temporatry);
	    void FreeMemberData();
    public:
        Order(MiString* products, size_t count);
        const MiString& operator[](unsigned index) const;
        size_t Count() const;
        ~Order();
};
