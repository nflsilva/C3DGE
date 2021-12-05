#ifndef TIME_HPP
#define TIME_HPP

#include <GLFW/glfw3.h>
static double d;
class Time {

  private:


  public:
    static double GetTime() { return glfwGetTime(); }
    static double GetDelta() { return d; }
    static void SetDelta(double delta){ d = delta; }

};

#endif