#include "Flight.h"

unsigned Flight::current_free_id = 0;

static bool IsSymbolicChar(char symbol) 
{
	return symbol >= 'A' && symbol <= 'z' || symbol == ' ';
}

static bool IsOnlySymbolic(const char* string) 
{	
	for (; *string; string++)
		if (!IsSymbolicChar(*string))
			return false;
	return false;
}

void Flight::SetDeparture(const char* string)
{
	if (IsOnlySymbolic(string))
	{
		size_t len = strlen(string) + 1;
		_placeOfDeparture = new char[len];
		strcpy_s(_placeOfDeparture, len, string);
	}
}

void Flight::SetDestination(const char* string)
{
	if (IsOnlySymbolic(string))
	{
		size_t len = strlen(string) + 1;
		_destination = new char[len];
		strcpy_s(_destination, len, string);
	}
}

Flight::Flight(const char* placeOfDeparture, const char* destination, unsigned timeOfDeparture)
{
	_id = Flight::current_free_id++;
	SetDeparture(placeOfDeparture);
	SetDestination(destination);
	_timeOfDeparture = timeOfDeparture;
}

void Flight::CopyData(const Flight& copy)
{
	_id = copy._id;
	SetDeparture(copy._placeOfDeparture);
	SetDestination(copy._destination);
	_timeOfDeparture = copy._timeOfDeparture;
}

void Flight::FreeData()
{
	delete[] _placeOfDeparture;
	_placeOfDeparture = nullptr;
	delete[] _destination;
	_destination = nullptr;
}

Flight::Flight(const Flight& copy)
{
	CopyData(copy);
}

Flight::~Flight() 
{
	FreeData();
}

Flight& Flight::operator=(const Flight& flight)
{
	if (this != &flight)
	{
		FreeData();
		CopyData(flight);
	}

	return *this;
}


unsigned Flight::ID() 
{
	return _id;
}

unsigned Flight::DepartTime()
{
	return _timeOfDeparture;
}

void Flight::SetDepartTime(unsigned newTime)
{
	_timeOfDeparture = newTime;
}