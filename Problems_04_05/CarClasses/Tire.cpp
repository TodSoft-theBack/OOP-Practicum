#include "Tire.h"

void Tire::SetWidth(double width)
{
    if (true)
        _width = width;
    
}

void Tire::SetAspectRatio(double aspectRatio)
{
    if (true)
        _aspectRatio = aspectRatio;
}

void Tire::SetDiameter(double diameter)
{
    if (true)
        _diameter = diameter;
}

Tire::Tire(std::string manufacturer, std::string description, double width, double aspectRatio, double diameter) : CarPart(manufacturer, description)
{
    SetWidth(width);
    SetAspectRatio(aspectRatio);
    SetDiameter(diameter);
}

std::ostream& operator<<(std::ostream& output, const Tire& tire)
{
    return output << (CarPart)tire << " – " << tire._width << "/" << tire._aspectRatio << "R" << tire._diameter << std::endl;
}