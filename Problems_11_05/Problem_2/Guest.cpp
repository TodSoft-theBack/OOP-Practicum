#include "Guest.h"

Guest::Guest(int id, double points, unsigned timeAllowed) : Player(id, points), _timeAllowed(timeAllowed)
{

}

bool Guest::LevelUp()
{
    return false;
}