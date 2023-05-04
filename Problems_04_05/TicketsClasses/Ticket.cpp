#include "Ticket.h"

Ticket::Ticket(const std::string& playName, double price ) : _playName(playName), _price(price) { }

void Ticket::Print() const
{
    std::cout << " Play: " << _playName << " Price: $" << _price << std::endl;
}
