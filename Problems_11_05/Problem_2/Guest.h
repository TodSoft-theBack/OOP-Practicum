#pragma once
#include "Player.h"

class Guest : public Player
{
    private:
        unsigned _timeAllowed;

    public:
        Guest(int id, double points, unsigned timeAllowed);
        bool LevelUp() override;
};

