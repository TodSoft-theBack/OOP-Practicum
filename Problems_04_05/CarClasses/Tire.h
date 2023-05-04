#include "CarPart.h"

class Tire : public CarPart
{
    private:
        double _width;
        double _aspectRatio;
        double _diameter;

        void SetWidth(double width);
        void SetAspectRatio(double aspectRatio);
        void SetDiameter(double diameter);

    public:
        Tire(std::string manufacturer, std::string description, double width, double aspectRatio, double diameter);
        friend std::ostream& operator<<(std::ostream& output, const Tire& tire); 
};