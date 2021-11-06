#ifndef CORE_ENGINE_HPP
#define CORE_ENGINE_HPP

#include "render/RenderEngine.hpp"
#include "core/GameObject.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "ui/UIEngine.hpp"

class CoreEngine {

  private:
    static const int TICKS_PER_SECOND = 60;
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;

    UIEngine* uiEngine;
    RenderEngine* renderEngine;
    CoreEngineDelegate* delegate;
    std::list<GameObject*> gameObjects;

    bool isRunning;

    void Run();
    void Update();
    void Render();

  public:
    CoreEngine();
    ~CoreEngine();
    void Start();
    void Stop();
    void AddGameObject(GameObject* object);
    void SetDelegate(CoreEngineDelegate* delegate);

    void MoveCameraToLeft();
    void MoveCameraToRight();
    void MoveCameraForward();
    void MoveCameraBackwards();
    void MoveCameraUp();
    void MoveCameraDown();
    void RotateSceneVerticalAxis(float angle);
    void RotateSceneHorizontalAxis(float angle);

};

#endif