#ifndef Dat_H
#define Dat_H
#include<iostream>
#include<iomanip>
using namespace std;

//Implemented class Date
class Date
{
private:
	int day;
	int month;
	int year;
public:
	// provided definitions of the constructors below
	inline Date(int day = 1, int month = 1, int year = 1); // parameterized constructor that initializes all data members

	//	Definations for mutators to access all private data members
	inline void setDay(int);
	inline void setMonth(int);
	inline void setYear(int);

	//	Definations for accessorsto access all private data members
	inline int getDay();
	inline int getMonth();
	inline int getYear();


	// Overload the << operator as a friend function
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

//********************************Out-line Functions********************************

// Implemented the constructors below

inline Date::Date(int day, int month, int year) // parameterized and default constructor that initializes all data members
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

//	Implemented mutators for all private data members
inline void Date::setDay(int dd)
{
	if (dd < 1 || dd > 31)
	{
		dd = 1;
	}

	day = dd;
}

inline void Date::setMonth(int mm)
{
	if (mm < 1 || mm > 12)
	{
		mm = 1;
	}

	month = mm;
}

inline void Date::setYear(int yyyy)
{
	if (yyyy < 1)
	{
		yyyy = 1;
	}

	year = yyyy;
}


//	Implemented accessors for all private data members
inline int Date::getDay()
{
	return day;
}

inline int Date::getMonth()
{
	return month;
}

inline int Date::getYear()
{
	return year;
}

std::ostream& operator<<(std::ostream& os, const Date& date);
#endif // HEADER_FILE_NAME_H