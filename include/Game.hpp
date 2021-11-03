#ifndef GAME_HPP
#define GAME_HPP

#include "core/CoreEngine.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "core/GameObject.hpp"

class Game : public CoreEngineDelegate {

  private:
    CoreEngine* engine;
    GameObject* triangle;
    Vertex vertexes[3] = {
      Vertex(-1, -1, 0),
      Vertex(0, 1, 0),
      Vertex(1, -1, 0),
    };

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