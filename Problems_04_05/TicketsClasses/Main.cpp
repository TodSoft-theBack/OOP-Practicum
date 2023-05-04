#include <iostream>
#include "Ticket.h"
#include "StudentTicket.h"
#include "GroupTicket.h"

int main(void)
{
    Ticket meme("Jojo\'s bizarre adventure!", 5.00);
    StudentTicket pepe("Jojo\'s bizarre adventure!", 5.00);
    GroupTicket shishi("Jojo\'s bizarre adventure!", 5.00);

    meme.Print();
    pepe.Print();
    shishi.Print();
    return EXIT_SUCCESS;
}