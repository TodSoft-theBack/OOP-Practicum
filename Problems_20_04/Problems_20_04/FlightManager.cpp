#include "FlightManager.h"

const size_t INITIAL_CAPACITY = 8;

FlightManager::FlightManager() : capacity(INITIAL_CAPACITY), count(0)
{
	flights = new Flight*[capacity];
}

void FlightManager::Resize(size_t newCapacity)
{
	Flight** newFlights = new Flight* [newCapacity];
	for (size_t i = 0; i < count; i++)
		newFlights[i] = new Flight(*flights[i]);
	FreeData();
	flights = newFlights;
}

void FlightManager::CopyData(const FlightManager& copy)
{	 
	capacity = copy.capacity;
	count = copy.count;
	flights = new Flight* [capacity];

	for (size_t i = 0; i < count; i++)
		flights[i] = new Flight(*copy.flights[i]);
}	 
	 
void FlightManager::FreeData()
{
	for (size_t i = 0; i < count; i++)
		delete flights[i];
	delete[] flights;
	flights = nullptr;
}

FlightManager::FlightManager(const FlightManager& copy)
{
	CopyData(copy);
}

FlightManager& FlightManager::operator= (const FlightManager& flightManager)
{
	if (this != &flightManager)
	{
		FreeData();
		CopyData(flightManager);
	}
	return *this;
}

void FlightManager::CreateFlight(const char* placeOfDeparture, const char* destination, unsigned timeOfDeparture)
{
	if (count + 1 >= capacity)
		Resize(capacity * 2);
	flights[count++] = new Flight(placeOfDeparture, destination, timeOfDeparture);
}

void FlightManager::DeleteFlight(unsigned ID)
{
	if (count - 1 <= capacity / 4)
		Resize(capacity / 2);
	int index = Find(ID);
	std::swap(flights[index], flights[count - 1]);
	delete flights[count - 1];
	count--;
}

int FlightManager::Find(unsigned ID)
{
	for (size_t i = 0; i < count; i++)
		if (flights[i]->ID() == ID)
			return i;
	return -1;
}

void FlightManager::ChangeDepartureTime(unsigned ID, unsigned newTime)
{
	int index = Find(ID);
	flights[index]->SetDepartTime(newTime);
}

void FlightManager::PrintAllFlights()
{
	for (size_t i = 0; i < count; i++)
		flights[i]->Print();
}