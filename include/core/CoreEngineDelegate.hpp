#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include "ui/InputState.hpp"

class CoreEngineDelegate {

  public:
    virtual void OnStart() = 0;
    virtual void OnInput(InputState input) = 0;
    virtual void OnUpdate(float elapsedTime) = 0;
    virtual void OnRender() = 0;
    virtual void OnDestroy() = 0;
};

#endif