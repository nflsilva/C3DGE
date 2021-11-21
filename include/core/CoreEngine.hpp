#ifndef CORE_ENGINE_HPP
#define CORE_ENGINE_HPP

#include "render/BaseModel.hpp"
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
    std::list<BaseModel*> gameObjects;

    bool isRunning;

    void Run();
    void Update(float elapsedTime);
    void Render();

  public:
    CoreEngine();
    ~CoreEngine();
    void Start();
    void Stop();
    void AddGameObject(BaseModel* object);
    void SetDelegate(CoreEngineDelegate* delegate);
    void SetCamera(BaseCamera* camera);
};

#endif