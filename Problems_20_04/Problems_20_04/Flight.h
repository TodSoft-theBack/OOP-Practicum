#include<iostream>
#pragma once
class Flight
{
	private:
		static unsigned current_free_id;
		unsigned _id = 0;
		char* _placeOfDeparture = nullptr;
		char* _destination = nullptr;
		unsigned _timeOfDeparture = 0;

		void CopyData(const Flight& copy);
		void FreeData();

		void SetDeparture(const char* string);
		void SetDestination(const char* string);

	public:
		Flight(const char* placeOfDeparture, const char* destination, unsigned timeOfDeparture);
		Flight(const Flight& copy);
		Flight& operator=(const Flight& flight);
		unsigned ID();
		unsigned DepartTime();
		void SetDepartTime(unsigned newTime);
		void Print();
	~Flight();
};

