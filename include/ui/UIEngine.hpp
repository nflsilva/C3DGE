#ifndef UI_ENGINE_HPP
#define UI_ENGINE_HPP

#include "ui/Window.hpp"
#include "ui/Keyboard.hpp"
#include "ui/Mouse.hpp"

class UIEngine {
  private:
    Window* window;
    Keyboard* keyboard;
    Mouse* mouse;

  public:
    UIEngine(int windowWidth, int windowHeight);
    ~UIEngine();

    bool IsRunning();

    void Update();
    void Render();
    void Close();

};

#endif