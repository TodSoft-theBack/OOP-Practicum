#pragma once
#include "Player.h"
#include <iostream>

class PremiumPlayer : public Player
{
    private:
        std::string username;
    
    public:
        PremiumPlayer(int id, double points, std::string username);
        void SendMessages(const char* message);
        bool LevelUp() override;
};
