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
        Update();
        if(delegate) delegate->OnInput(uiEngine->GetInputState());
        updates++;
        timeToTick = tickTime;
    }
    Render();
    frames++;

    if (Time::GetTime() > seconds) {
        Log::D(std::to_string(frames) + " " + std::to_string(Time::GetDelta()));
        updates = 0, frames = 0;
        seconds++;
    }

    if(!uiEngine->IsRunning()) Stop();
	}
}

void CoreEngine::Update(){
  if(delegate) delegate->OnUpdate();
  renderEngine->Update();
  uiEngine->Update();
}

void CoreEngine::Render(){
  renderEngine->ClearScreen();
  if(delegate) delegate->OnRender();
  for(auto o : gameObjects)
    renderEngine->Render(o->renderComponents);
  uiEngine->Render();
}

void CoreEngine::AddGameObject(GameObject* object){
  gameObjects.push_front(object);
}
void CoreEngine::SetDelegate(CoreEngineDelegate* delegate){
  this->delegate = delegate;
}

void CoreEngine::MoveCameraToLeft(){
  renderEngine->MoveCameraLeft();
};
void CoreEngine::MoveCameraToRight(){
  renderEngine->MoveCameraRight();
};
void CoreEngine::MoveCameraForward(){
  renderEngine->MoveCameraFoward();
};
void CoreEngine::MoveCameraBackwards(){
  renderEngine->MoveCameraBackwards();
};
void CoreEngine::MoveCameraUp(){
  renderEngine->MoveCameraUp();
};
void CoreEngine::MoveCameraDown(){
  renderEngine->MoveCameraDown();
};
void CoreEngine::RotateSceneVerticalAxis(float angle){
  renderEngine->RotateSceneVerticalAxis(angle); 
}
void CoreEngine::RotateSceneHorizontalAxis(float angle){
  renderEngine->RotateSceneHorizontalAxis(angle); 
}

