#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <algorithm>

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
    static void Utils::recursiveToUpper(char str[]);
    
    // TODO: 2 versions of ToUpper
};