#include "Date.h"


Date::Date(const int& day, const int& month, const int& year):
	day(day), month(month), year(year)
{
	
}


std::string Date::getDate() const
{

	return std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
	
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

bool Date::compareDate(const int& day, const int& month, const int& year) const
{

	if (this->year > year) return true;
	else if(this->month > month) return true;
	else if (this->day > day) return true;

	return false;
	
}

bool Date::compareDate(const std::string& date) const
{

	try{
		return strcmp(date.c_str(), getDate().c_str()) < 0;
	}
	catch(...){
		return false;
	}

	return false;

}
