#ifndef GAME_HPP
#define GAME_HPP

#include "core/CoreEngine.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "core/GameObject.hpp"

class Game : public CoreEngineDelegate {

  private:
    CoreEngine* engine;
    GameObject* triangle;
    std::vector<Vertex> vertices = {
      Vertex(-1, -1, 0),
      Vertex( 0,  1, 0),
      Vertex( 1, -1, 0),
      Vertex( 0, -1, 1),
      Vertex( 0, -1, -1)
    };
    std::vector<int> indices = { 
      0, 1, 3,
      3, 1, 2,
      2, 1, 0,
      0, 2, 3,
      0, 2, 4,
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