#ifndef GAME_HPP
#define GAME_HPP

#include "iGameLogic.hpp"

class Game : public iGameLogic {

  public:
    Game();
    ~Game();

    void OnStart();
    void OnInput(Keyboard* keyboard, Mouse* mouse);
    void OnUpdate();
    void OnRender();
    void OnDestroy();

};

#endif