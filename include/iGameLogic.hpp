#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

class iGameLogic {

  public:
    virtual void OnStart() = 0;
    virtual void OnInput(Keyboard* keyboard) = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    virtual void OnDestroy() = 0;
};

#endif