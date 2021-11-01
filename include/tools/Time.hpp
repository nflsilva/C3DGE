#ifndef TIME_HPP
#define TIME_HPP

#include <GLFW/glfw3.h>

class Time {

  private:
    //static double delta;

  public:
    static double GetTime() { return glfwGetTime(); }
    //static double GetDelta() { return delta; }
    //static void SetDelta(double delta){ Time::delta = delta; }

};

#endif