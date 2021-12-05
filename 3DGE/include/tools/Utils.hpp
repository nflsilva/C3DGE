#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <string.h>

class Utils {

  public:
    static char* StringToCharArray(std::string s) { 
      char *r = new char[s.length() + 1];
      strcpy(r, s.c_str());
      return r;
    }
};

#endif