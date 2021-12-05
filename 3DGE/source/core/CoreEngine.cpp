#include "core/CoreEngine.hpp"
#include "tools/Log.hpp"
#include "tools/Time.hpp"

#include <stdio.h>
#include <chrono>
#include <ctime>
#include <thread>

CoreEngine::CoreEngine() : delegate(NULL), isRunning(false) {
  uiEngine = new UIEngine(WIDTH, HEIGHT);
  renderEngine = new RenderEngine(WIDTH, HEIGHT); 
}
CoreEngine::~CoreEngine(){
  if(delegate) delegate->OnDestroy();
  for(auto o : gameObjects) delete(o);
  delete(renderEngine);
  delete(uiEngine);
}

void CoreEngine::Start(){
  if(isRunning){
    return;
  }
  isRunning = true;
  renderEngine->Init();
  if(delegate) delegate->OnStart();
  Run();
}

void CoreEngine::Stop(){
  if(!isRunning){
    return;
  }
  isRunning = false;
}

void CoreEngine::Run(){

  double tickTime =  (double)1 / TICKS_PER_SECOND;
  double nowTime = 0, lastTime = 0, deltaTime = 0, timeToTick = 0;
  int frames = 0, updates = 0, seconds = 0;

	while(isRunning){

    nowTime = Time::GetTime();
    deltaTime = (nowTime - lastTime);
    timeToTick -= deltaTime;
    lastTime = nowTime;

    Time::SetDelta(deltaTime);
    //Log::D("N: " + std::to_string(nowTime) + " D: " + std::to_string(deltaTime) + " S: " + std::to_string(seconds) );

    if(timeToTick <= 0){
        InputState input = uiEngine->GetInputState();
        Update(deltaTime, input);
        updates++;
        timeToTick = tickTime;
    }
    Render();
    frames++;

    if (Time::GetTime() > seconds) {
        Log::D(std::to_string(frames) + " " + std::to_string(Time::GetDelta()) + " " + std::to_string(updates));
        updates = 0, frames = 0;
        seconds++;
    }

    if(!uiEngine->IsRunning()) Stop();
	}
}

void CoreEngine::Update(float elapsedTime, InputState input){
  if(delegate) delegate->OnUpdate(elapsedTime, input);
  for(auto o : gameObjects){
    o->Update(elapsedTime, input);
  }
  for(auto l : directionalLights){
    l->Update(elapsedTime, input);
  }
  renderEngine->Update(elapsedTime, input);
  uiEngine->Update(elapsedTime, input);
}

void CoreEngine::Render(){
  if(delegate) delegate->OnRender();
  renderEngine->Render(gameObjects, directionalLights);
  uiEngine->Render();
}

void CoreEngine::AddGameObject(GameObject* object){
  gameObjects.push_front(object);
}
void CoreEngine::AddDirectionalLight(DirectionalLight* light){
  directionalLights.push_front(light);
}

void CoreEngine::SetDelegate(CoreEngineDelegate* delegate){
  this->delegate = delegate;
}
void CoreEngine::SetCamera(BaseCamera* camera) {
  renderEngine->SetCamera(camera);
}

