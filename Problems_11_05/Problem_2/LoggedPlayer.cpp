#include "LoggedPlayer.h"


LoggedPlayer::LoggedPlayer(int id, double points, std::string password) : Player(id, points), password(password)
{

}

bool LoggedPlayer::LogIn(int id, std::string password)
{
    
}