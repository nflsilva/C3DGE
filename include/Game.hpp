#ifndef GAME_HPP
#define GAME_HPP

#include "ui/Keyboard.hpp"
#include "iGameLogic.hpp"

class Game : public iGameLogic {

  public:
    Game();
    ~Game();

    void OnStart();
    void OnInput(Keyboard* keyboard);
    void OnUpdate();
    void OnRender();
    void OnDestroy();

};

#endif