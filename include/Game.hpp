#ifndef GAME_HPP
#define GAME_HPP

#include "core/CoreEngine.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "core/GameObject.hpp"

class Game : public CoreEngineDelegate {

  private:
    CoreEngine* engine;
    GameObject* triangle;
    float f = 0;
    RenderComponent* trComponent;


  public:
    Game(CoreEngine* engine);
    ~Game();

    void OnStart();
    void OnInput();
    void OnUpdate();
    void OnRender();
    void OnDestroy();

};

#endif