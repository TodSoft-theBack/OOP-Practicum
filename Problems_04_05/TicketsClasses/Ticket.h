#pragma once
#include <iostream>
#include <cstring>

class Ticket
{
    private:
        std::string _playName;
        double _price;
    public:
        Ticket(const std::string& playName, double price );
        void Print() const;
};
