#pragma once
#include "Flight.h"
class FlightManager
{
	private:
		Flight** flights = nullptr;
		size_t capacity;
		size_t count;

		void Resize(size_t newCapacity);
		void CopyData(const FlightManager& copy);
		void FreeData();

	public:
		FlightManager();
		FlightManager(const FlightManager& copy);
		FlightManager& operator= (const FlightManager& flightManager);
		void CreateFlight(const char* placeOfDeparture, const char* destination, unsigned timeOfDeparture);
		void DeleteFlight(unsigned ID);
		int Find(unsigned ID);
		void ChangeDepartureTime(unsigned ID, unsigned newTime);
		void PrintAllFlights();
	~FlightManager();
};

