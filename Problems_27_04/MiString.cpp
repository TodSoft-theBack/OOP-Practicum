#include "MiString.h"

void MiString::CopyMemberData(const MiString& copy)
{
	if(copy.IsSmallString())
	{
		strcpy(_data._static, copy._data._static);
		_capacity = SMALL_STRING_MAX_SIZE;
	}
	else
	{
		_capacity = copy._capacity;
		_data._dynamic._string = new char[_capacity];
	}
}

void MiString::FreeMemberData()
{
	if(!IsSmallString())
	{
		delete[] _data._dynamic._string;
		_data._dynamic._string = nullptr;
	}
}

void MiString::MoveMemberData(MiString&& temporary)
{
	if (!IsSmallString())
	{
		_data._dynamic = temporary._data._dynamic;
		temporary._data._dynamic._string  = nullptr;
		_capacity = temporary._capacity;
	}

	CopyMemberData(temporary);
}

bool MiString::IsSmallString() const
{
	return _capacity == SMALL_STRING_MAX_SIZE;
}

MiString::MiString()
{
	_capacity = SMALL_STRING_MAX_SIZE;
	_data._static[0] = '\0';
}

MiString::MiString(size_t capacity)
{
	if (capacity <= SMALL_STRING_MAX_SIZE)
	{
		_capacity = SMALL_STRING_MAX_SIZE;
		_data._static[0] = '\0';
	}
	else
	{
		_capacity = capacity;
		_data._dynamic._string = new char[_capacity];
		_data._dynamic._length = 0;
		_data._dynamic._string[0] = '\0';
	}
}

MiString::MiString(const char* data)
{
	size_t capacity = strlen(data) + 1;
	if(capacity <= SMALL_STRING_MAX_SIZE)
	{
		strcpy(_data._static, data);
		_capacity = SMALL_STRING_MAX_SIZE;
	}		
	else
	{
		_data._dynamic._string = new char[capacity];
		_data._dynamic._length = capacity - 1;
		strcpy(_data._dynamic._string, data);
		_capacity = capacity;
	}
	
}

MiString::MiString(const MiString& string)
{
	CopyMemberData(string);
}

MiString::MiString(MiString&& temporary)
{
	MoveMemberData(std::move(temporary));
}

size_t MiString::Length() const
{
	if(IsSmallString())
		return strlen(_data._static);
	return _data._dynamic._length;
}

const char* MiString::Data() const
{
	if (IsSmallString())
		return _data._static;
	return _data._dynamic._string;
}

MiString& MiString::operator=(const MiString& string)
{
	if (this != &string)
	{
		FreeMemberData();
        CopyMemberData(string);
	}
	return *this;
}

MiString& MiString::operator=(MiString&& string)
{
	if (this != &string)
	{
		FreeMemberData();
        MoveMemberData(std::move(string));
	}
	return *this;
}

MiString& MiString::operator+=(const MiString& rhs)
{
	size_t thisLen = Length(), thatLen = rhs.Length();
	size_t resultCapacity = thisLen + thatLen + 1;

	if (IsSmallString() && resultCapacity <= SMALL_STRING_MAX_SIZE)
	{
		strcat(_data._static, rhs.Data());
		return *this;
	}

	if (!IsSmallString() && resultCapacity <= _capacity)
	{
		strcat(_data._dynamic._string, rhs.Data());
		_data._dynamic._length = resultCapacity - 1;
		return *this;
	}
	
	char* result = new char[resultCapacity];
	result[0] = '\0';
	strcat(result, Data());
	strcat(result, rhs.Data());

	if (!IsSmallString())
		delete[] _data._dynamic._string;
	
	_data._dynamic._string = result;
	_data._dynamic._length = resultCapacity - 1;
	_capacity = resultCapacity;

	return *this;
}

char& MiString::operator[](unsigned index)
{
	if(IsSmallString())
		return _data._static[index];
	else
		return _data._dynamic._string[index];
}

char MiString::operator[](unsigned index) const 
{
	if(IsSmallString())
		return _data._static[index];
	else
		return _data._dynamic._string[index];
}

MiString operator+(const MiString& lhs, const MiString& rhs)
{
	size_t capacity = lhs.Length() + rhs.Length() + 1;
	MiString result(capacity);
	result += lhs.Data();
	result += rhs.Data();
	return result;
}

std::ostream& operator<<(std::ostream& output, const MiString& string)
{
	if(string.IsSmallString())
		return output << string._data._static;
	else
		return output << string._data._dynamic._string;
   
}

std::istream& operator>>(std::istream& input, MiString& string)
{
	if(string.IsSmallString())
		return input >> string._data._static;
	else
	{
		return input >> string._data._dynamic._string;
	}
}

MiString::~MiString()
{
	FreeMemberData();
}