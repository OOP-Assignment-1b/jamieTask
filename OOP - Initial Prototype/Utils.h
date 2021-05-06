#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <iomanip>
#include <sstream>

class Utils
{
  public:
    static const std::string getLineFromUser();
    static const char getCharFromUser();
    static const int getYear();
    static const int getMonth();
    static const int getDay();
    static const std::string toLower(const std::string& string);

    static const std::string toUpper(const std::string& string);
    static const std::string recursiveToUpper(std::string str);

    static const int getRandomNumber(const int& max, const int& min);

    static const std::string formatPlayTime(double& time, const std::string& name);
    static const std::string formatCurrency(const std::string& text, const double& ammount);
    
    static const bool startsWith(const std::string& fullText, const std::string& searchText);
    
};