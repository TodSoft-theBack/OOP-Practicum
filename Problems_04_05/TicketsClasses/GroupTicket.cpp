#include "GroupTicket.h"

GroupTicket::GroupTicket(const char* playName, double price) : Ticket(playName, price * (1 - 0.2)) { }