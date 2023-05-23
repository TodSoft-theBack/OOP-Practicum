#pragma once
#include "Player.h"
#include <iostream>

class LoggedPlayer : public Player
{
    private:
        std::string password;

    public:
        LoggedPlayer(int id, double points, std::string password);
        bool LogIn(int id, std::string password);
};

