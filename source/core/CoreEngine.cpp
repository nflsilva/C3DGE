#include "core/CoreEngine.hpp"
#include "tools/Log.hpp"
#include "tools/Time.hpp"

#include <stdio.h>
#include <chrono>
#include <ctime>
#include <thread>

CoreEngine::CoreEngine() : isRunning(false) {
  uiEngine = new UIEngine(WIDTH, HEIGHT);
  renderEngine = new RenderEngine(WIDTH, HEIGHT); 
  delegate = new NullCoreEngineDelegate();
}
CoreEngine::~CoreEngine(){}

void CoreEngine::Start(){
  if(isRunning){
    return;
  }
  isRunning = true;
  renderEngine->Init();
  delegate->OnStart();
  Run();
}

void CoreEngine::Stop(){
  if(!isRunning){
    return;
  }
  isRunning = false;
}

void CoreEngine::Run(){

  const double frameTime = 1.0 / FRAME_CAP;

  double lastTime = Time::GetTime(), timer = lastTime;
  double deltaTime = 0, nowTime = 0;
  int frames = 0, updates = 0;

	while(isRunning){

    nowTime = Time::GetTime();
    deltaTime += (nowTime - lastTime) / frameTime;
    lastTime = nowTime;

    while (deltaTime >= 1.0){
        delegate->OnInput();
        Update();
        updates++;
        deltaTime--;
    }
    Render();
    frames++;

    if (Time::GetTime() - timer > 1.0) {
        timer++;
        Log::D(std::to_string(frames));
        updates = 0, frames = 0;
    }

    if(!uiEngine->IsRunning()){
      Stop();
    }
	}

}

void CoreEngine::Update(){
  delegate->OnUpdate();
  uiEngine->Update();
}

void CoreEngine::Render(){
  delegate->OnRender();
  for(auto o : gameObjects)
    renderEngine->Render(o->renderComponents);
  uiEngine->Render();
}

void CoreEngine::Destroy(){
  delegate->OnDestroy();
  uiEngine->Close();
}

void CoreEngine::AddGameObject(GameObject* object){
  gameObjects.push_front(object);
}
void CoreEngine::SetDelegate(CoreEngineDelegate* delegate){
  this->delegate = delegate;
}