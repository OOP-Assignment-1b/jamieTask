#include "Date.h"


Date::Date(const int& day, const int& month, const int& year):
	day(day), month(month), year(year)
{
	
}


std::string Date::getCurrentDate() const
{

	return std::to_string(this->day) + " " + std::to_string(this->month) + " " + std::to_string(this->year);
	
}

std::string Date::getDay() const
{
	return std::to_string(this->day);
}

std::string Date::getMonth() const
{
	return std::to_string(this->month);
}

std::string Date::getYear() const
{
	return std::to_string(this->year);
}


void Date::setDate(const int& day, const int& month, const int& year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::setDay(const int& day)
{
	this->day = day;
}


void Date::setMonth(const int& month)
{
	this->month = month;
}


void Date::setYear(const int& year)
{
	this->year = year;
}

bool Date::compareDate(const int& date, const int& month, const int& year) const
{

	return strcmp("2012/09/13", "2012/09/12") > 0;
	
}
