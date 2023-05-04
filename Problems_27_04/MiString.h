#pragma once
#include <iostream>
#include <cstring>

class MiString
{
    static const unsigned SMALL_STRING_MAX_SIZE = sizeof(size_t) + sizeof(char*);

    private:

		//Data
		union 
		{
			char _static[SMALL_STRING_MAX_SIZE];
			struct
			{
				char* _string;
	    		size_t _length;
			} _dynamic;
		} _data;
		size_t _capacity;
        
		//Private fucntions
	    void CopyMemberData(const MiString& copy);
	    void FreeMemberData();
		void MoveMemberData(MiString&& temporary);
		bool IsSmallString() const;

    public:

		//Constructors
	    MiString();
		MiString(size_t capacity);
	    MiString(const char* string);
	    MiString(const MiString& copy);
		MiString(MiString&& temporary);

		//Public interface
		size_t Length() const;
		const char* Data() const;
		bool IsNullOrEmpty() const;
		static void Trim(char* string);
		MiString& Trim();

		static unsigned CountChar(const char* string, char _char);
		unsigned CountChar(char _char);

		//Operators
	    MiString& operator=(const MiString& string);
		MiString& operator=(MiString&& temporary);       
	    MiString& operator+=(const MiString& rhs);
	    char& operator[](unsigned index);
	    char operator[](unsigned index) const;

		friend MiString operator+(const MiString& lhs, const MiString& rhs);
        friend std::ostream& operator<<(std::ostream& output, const MiString& string);
		friend std::istream& operator>>(std::istream& output, MiString& string);

		//Destructor
	    ~MiString();
};