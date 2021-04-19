#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    static const int getYear();
    static const int getMonth();
    static const int getDay();
    
    // TODO: 2 versions of ToUpper
};