#pragma once

#include <string>

class Date
{


public:

	Date(const int& date, const int& month, const int& year);
	
	std::string getCurrentDate() const;
	std::string getDay() const;
	std::string getMonth() const;
	std::string getYear() const;

	
	void setDate(const int& day, const int& month, const int& year);
	void setDay(const int& day);
	void setMonth(const int& month);
	void setYear(const int& year);
	
	bool compareDate(const int& day, const int& month, const int& year) const;
	bool compareDate(const std::string& date) const;


private:
	int day;
	int month;
	int year;
	
};

