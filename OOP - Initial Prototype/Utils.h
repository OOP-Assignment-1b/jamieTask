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
    static std::string getLineFromUser();
    static char getCharFromUser();
    static const int getYear();
    static const int getMonth();
    static const int getDay();
    static std::string toLower(const std::string& string);

    static std::string toUpper(const std::string& string);
    static std::string recursiveToUpper(std::string str);

    static std::string formatPlayTime(double& time, const std::string& name);

    static int getRandomNumber(const int& max, const int& min);
    
};