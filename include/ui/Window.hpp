#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <GLFW/glfw3.h>
#include "ui/Keyboard.hpp"

class Window {

  private:
    static Window* instance;

    int width; 
    int height;
    std::string title;
    GLFWwindow* window;
    Keyboard* keyboard;

    Window(int width, int height, std::string title);
    ~Window();

    static void ErrorCallback(int error, const char* description);
    static void CloseCallback(GLFWwindow* window);

  public:
    static Window* Create(int width, int height, std::string title);

    Window(Window &other) = delete;
    void operator=(const Window &) = delete;

    Keyboard* GetKeyboard();

    void Close();
    bool IsRunning();
    void Update();

};

#endif