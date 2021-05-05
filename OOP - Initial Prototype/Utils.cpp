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

std::string Utils::recursiveToUpper (std::string str)
{
    std::string result;
    if (str[0] == '\0') return result;
    result = toupper(str[0]);
    str.erase(str.begin());
    return result += recursiveToUpper(str);

}

