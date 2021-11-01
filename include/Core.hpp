#ifndef CORE_HPP
#define CORE_HPP

#include "ui/Window.hpp"
#include "Game.hpp"

class Core {

  private:
    iGameLogic* game;
    Window* window;
    Keyboard* keyboard;
    Mouse* mouse;

    bool isRunning;

    static const int WIDTH = 640;
    static const int HEIGHT = 480;
    static constexpr double FRAME_CAP = 5000.0;

    void Run();
    void Update();
    void Render();
    void Destroy();

  public:
    Core();
    ~Core();
    void Start();
    void Stop();

};

#endif