#pragma once

#include <string>

class Date
{


public:

	Date() = default;
	Date(const int& date, const int& month, const int& year);
	
	std::string getCurrentDate() const;
	std::string getDay() const;
	std::string getMonth() const;
	std::string getYear() const;

	
	void setDate(const int& date, const int& month, const int& year);
	void setDay(const int& day);
	void setMonth(const int& month);
	void setYear(const int& year);
	
	bool compareDate(const int& date, const int& month, const int& year) const;


private:
	int day;
	int month;
	int year;
	
};

