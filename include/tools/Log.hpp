#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <iostream>

class Log {

  public:
    static void E(std::string log){
      Write("[ERROR]> " + log);
    }
    static void D(std::string log){
      Write("[DEBUG]> " + log);
    }
    static void I(std::string log){
      Write("[INFO]> " + log);
    }
  private:
    static void Write(std::string log){
      std::cout << log << std::endl;
    }

};

#endif