#include "Footpanda.h"

void Footpanda::CopyMemberData(const Footpanda& copy)
{
    restaurants = new Restaurant*[copy._capacity];
    for (size_t i = 0; i < copy._count; i++)
        restaurants[i] = new Restaurant(*copy.restaurants[i]);
    _count = copy._count;
    _capacity = copy._capacity;
}

void Footpanda::MoveMemberData(Footpanda&& temporatry)
{
    restaurants = temporatry.restaurants;
    temporatry.restaurants = nullptr;
    _count = temporatry._count;
    _capacity = temporatry._capacity;
}

void Footpanda::FreeMemberData()
{
    for (size_t i = 0; i < _count; i++)
        delete restaurants[i];
    delete[] restaurants;
    restaurants = nullptr;
}

Footpanda::Footpanda(size_t capacity)
{
    restaurants = new Restaurant*[capacity];
    _count = 0;
}

void Footpanda::AddRestaurant(const Restaurant& newRestaurant)
{
    restaurants[_count++] = new Restaurant(newRestaurant);
}

void Footpanda::AddRestaurant(Restaurant&& newRestaurant)
{
    restaurants[_count++] = new Restaurant(std::move(newRestaurant));
}

void Footpanda::Run()
{
    char line[1024];
    do
    {
        std::cin.getline(line, 1024);
    } 
    while (strcmp(line, "Quit life") == 0);
}

Footpanda::~Footpanda()
{
}
