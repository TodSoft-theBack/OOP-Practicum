#pragma once
#include "Order.h"
#include "MiString.h"


class Restaurant
{
    public:
        static const size_t RESTRAURANT_NAME_SIZE = 25ul;

    private:
        char name[25];
        MiString* products;
        size_t count;
        size_t _capacity;

        void CopyMemberData(const Restaurant& copy);
        void MoveMemberData(Restaurant&& temporatry);
	    void FreeMemberData();

    public:
        Restaurant(size_t capacity);
        Restaurant(const Restaurant& copy);
        Restaurant(Restaurant&& temporary);

        Restaurant& operator= (const Restaurant& restaurant);
        Restaurant& operator= (Restaurant&& restaurant);

        bool Contains(const MiString& product);
        void AddProduct(const MiString& product);
        void AddProduct(MiString&& product);
        unsigned ProcessOrder(const Order& order);
        ~Restaurant();
};

