#ifndef CORE_ENGINE_HPP
#define CORE_ENGINE_HPP

#include "render/RenderEngine.hpp"
#include "core/GameObject.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "ui/UIEngine.hpp"

class CoreEngine {

  private:
    static const int WIDTH = 640;
    static const int HEIGHT = 480;
    static constexpr double FRAME_CAP = 5000.0;

    UIEngine* uiEngine;
    RenderEngine* renderEngine;
    CoreEngineDelegate* delegate;

    std::list<GameObject*> gameObjects;

    bool isRunning;

    void Run();
    void Update();
    void Render();
    void Destroy();

  protected:
    class NullCoreEngineDelegate : public CoreEngineDelegate {
      public:
        NullCoreEngineDelegate(){}
        void OnStart(){}
        void OnInput(){}
        void OnUpdate(){}
        void OnRender(){}
        void OnDestroy(){}
    };

  public:
    CoreEngine();
    ~CoreEngine();
    void Start();
    void Stop();
    void AddGameObject(GameObject* object);
    void SetDelegate(CoreEngineDelegate* delegate);

};

#endif