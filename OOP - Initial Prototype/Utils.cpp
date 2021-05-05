#include "Utils.h"

std::string Utils::getLineFromUser() 
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

const int Utils::getYear() {
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int year = newtime.tm_year + 1900;
    return year;
}

const int Utils::getMonth() {
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int Month = 1 + newtime.tm_mon;
    return Month;
}

const int Utils::getDay() {
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int day = newtime.tm_mday;
    return day;
}

std::string Utils::toLower(const std::string& string)
{
    std::string c;
    for(int i=0; i < string.length(); i++)
    {
        c+=tolower(string[i]);
    }
    return c;
}

std::string Utils::toUpper(const std::string& string)
{
    std::string c;
    for (int i = 0; i < string.length(); i++)
    {
        c += toupper(string[i]);
    }
    return c;
}

void Utils::recursiveToUpper (char str[])
{

    if (str[0] == '\0') return;
    str[0] = toupper(str[0]);
    recursiveToUpper(str + 1);

}

int Utils::getRandomNumber(const int& max, const int& min)
{

    return rand() % (max - 10) + min;
	
}

std::string Utils::formatPlayTime(double& time, const std::string& name)
{
    std::string suffix;

    if (time < 1)
    {
        time *= 60;
        suffix = " Minutes)";
    }
    else
    {
        suffix = " Hours)";
    }

    if (time >= 5)
    {
        time = static_cast<int>(time);
    }
    std::stringstream formatStringThree;
    formatStringThree << std::left << std::setfill(' ') << std::setw(15) << name << std::setprecision(2) << '(' << time << suffix;
    return formatStringThree.str();

	
}


