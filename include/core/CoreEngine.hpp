#ifndef CORE_ENGINE_HPP
#define CORE_ENGINE_HPP

#include "core/GameObject.hpp"
#include "render/RenderEngine.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "ui/UIEngine.hpp"

class CoreEngine {

  private:
    static const int TICKS_PER_SECOND = 128;
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;

    UIEngine* uiEngine;
    RenderEngine* renderEngine;
    CoreEngineDelegate* delegate;
    std::list<GameObject*> gameObjects;

    bool isRunning;

    void Run();
    void Update(float elapsedTime, InputState input);
    void Render();

  public:
    CoreEngine();
    ~CoreEngine();
    void Start();
    void Stop();
    void AddGameObject(GameObject* object);
    void SetDelegate(CoreEngineDelegate* delegate);
    void SetCamera(BaseCamera* camera);
};

#endif