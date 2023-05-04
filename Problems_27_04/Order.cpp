#include "Order.h"


void Order::CopyMemberData(const Order& copy)
{

}

void Order::MoveMemberData(Order&& temporatry)
{

}

void Order::FreeMemberData()
{

}


Order::Order(MiString* products, size_t count)
{

}

const MiString& Order::operator[](unsigned index) const
{
    return products[index];
}

size_t Order::Count() const
{
    return count;
}

Order::~Order()
{
    FreeMemberData();
}