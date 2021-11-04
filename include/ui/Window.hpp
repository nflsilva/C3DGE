#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <GLFW/glfw3.h>
#include "ui/Keyboard.hpp"
#include "ui/Mouse.hpp"

class Window {

  private:
    int width; 
    int height;
    std::string title;
    GLFWwindow* window;

    static void ErrorCallback(int error, const char* description);
    static void CloseCallback(GLFWwindow* window);

  public:
    Window(int width, int height, std::string title);
    ~Window();

    bool IsRunning();
    void Update();
    void Render();

};

#endif