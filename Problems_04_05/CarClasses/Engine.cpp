#include "Engine.h"

Engine::Engine(std::string manufacturer, std::string description, unsigned horsepower) : CarPart(manufacturer, description), horsepower(horsepower)
{

}

std::ostream& operator<<(std::ostream& output, const Engine& engine)
{
    return output << (CarPart)engine << " – " << engine.horsepower << " hp" << std::endl;
}