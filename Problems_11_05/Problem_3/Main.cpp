#include <iostream>
#include "Computer.h"
#include "Laptop.h"
#include "PC.h"
#include "GamingConsole.h"

int main()
{
    PC meme(1.5, "GTX 1050TI", 500, 16);
    Laptop pepe(1.5, "GTX 1050TI", 500, 16);
    GamingConsole shishi(1.5, "GTX 1050TI", 500, 16);

    meme.Type();
    pepe.Type();
    shishi.Type();

    meme.Peripherals();
    pepe.Peripherals();
    shishi.Peripherals();
    return EXIT_SUCCESS;
}