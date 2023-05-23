#pragma once

enum class Stars
{
    One,
    Two = 256,
    Three = 512,
    Four = 1024,
    Five = 2048
};

class Player
{
    private:
        int ID;
        double _points = 0;
        Stars _stars = Stars :: One;
         
    public:
        Player(int id, double points);
        virtual bool LevelUp();
        virtual ~Player() = default;
};
