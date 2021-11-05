#ifndef GAME_HPP
#define GAME_HPP

#include "core/CoreEngine.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "core/GameObject.hpp"

class Game : public CoreEngineDelegate {

  private:
    CoreEngine* engine;

    float f = 0;
    GameObject* teddy;
    GameObject* cow;
    GameObject* teapot;

  public:
    Game(CoreEngine* engine);
    ~Game();

    void OnStart();
    void OnInput(InputState input);
    void OnUpdate();
    void OnRender();
    void OnDestroy();

};

#endif