#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include "ui/Keyboard.hpp"
#include "ui/Mouse.hpp"

class iGameLogic {

  public:
    virtual void OnStart() = 0;
    virtual void OnInput(Keyboard* keyboard, Mouse* mouse) = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    virtual void OnDestroy() = 0;
};

#endif