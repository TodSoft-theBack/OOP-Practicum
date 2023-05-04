#include "Restaurant.h"

void Restaurant::CopyMemberData(const Restaurant& copy)
{
    _capacity = copy._capacity;
    count = copy.count;
    products = new MiString[_capacity];
    for (size_t i = 0; i < count; i++)
        products[i] = copy.products[i];
}

void Restaurant::MoveMemberData(Restaurant&& temporatry)
{
    products = temporatry.products;
    temporatry.products = nullptr;
    _capacity = temporatry._capacity;
    count = temporatry.count;
}

void Restaurant::FreeMemberData()
{
    delete[] products; 
    products = nullptr;  
}

Restaurant::Restaurant(size_t capacity)
{
    products  = new MiString[capacity];
    _capacity = capacity;
    count = 0;
}

Restaurant::Restaurant(const Restaurant& copy)
{
    CopyMemberData(copy);
}

Restaurant::Restaurant(Restaurant&& temporary)
{
    MoveMemberData(std::move(temporary));
}

Restaurant& Restaurant::operator= (const Restaurant& restaurant)
{
    if (this != &restaurant)
    {
        FreeMemberData();
        CopyMemberData(restaurant);
    }
    return *this;
}

Restaurant& Restaurant::operator= (Restaurant&& restaurant)
{
    if (this == &restaurant)
    {
        FreeMemberData();
        MoveMemberData(std::move(restaurant));
    }       
    return *this;
}

bool Restaurant::Contains(const MiString& product)
{
    for (size_t i = 0; i < count; i++)
        if (*(products[i]) == product)
            return true;
    return false;
}

void Restaurant::AddProduct(const MiString& product)
{
    if (Contains(product))
    {
        /* Kill thyself for you are so useless */
    }
    
    products[count++] = product;
}

void Restaurant::AddProduct(MiString&& product)
{
    if (Contains(product))
    {
        /* Kill thyself for you are so useless */
    }

    products[count++] = std::move(product);
}

unsigned Restaurant::ProcessOrder(const Order& order)
{
    size_t count = order.Count();
    for (size_t i = 0; i < count; i++)
        if (Contains(order[i]))
            throw std::invalid_argument("Your fatass is too greedy");
        
    
    return 5;
}

Restaurant::~Restaurant()
{
    FreeMemberData(); 
}