#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <GLFW/glfw3.h>
#include "ui/Keyboard.hpp"
#include "ui/Mouse.hpp"

class Window {

  private:
    static Window* instance;

    int width; 
    int height;
    std::string title;
    GLFWwindow* window;
    Keyboard* keyboard;
    Mouse* mouse;

    Window(int width, int height, std::string title);
    ~Window();

    static void ErrorCallback(int error, const char* description);
    static void CloseCallback(GLFWwindow* window);

  public:
    static Window* Create(int width, int height, std::string title);

    Window(Window &other) = delete;
    void operator=(const Window &) = delete;

    Keyboard* GetKeyboard();
    Mouse* GetMouse();

    void Close();
    bool IsRunning();
    void Update();
    void Render();

};

#endif