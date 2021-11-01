#include "tools/Log.hpp"
#include "tools/Time.hpp"
#include "Core.hpp"

#include <stdio.h>
#include <chrono>
#include <ctime>
#include <thread>

Core::Core() : isRunning(false) {
  window = Window::Create(WIDTH, HEIGHT, "3DGE Example");
  keyboard = window->GetKeyboard();
}
Core::~Core(){}

void Core::Start(){
  if(isRunning){
    return;
  }
  isRunning = true;
  Run();
}

void Core::Stop(){
  if(!isRunning){
    return;
  }
  isRunning = false;
}

void Core::Run(){

  const double frameTime = 1.0 / FRAME_CAP;

  double lastTime = Time::GetTime(), timer = lastTime;
  double deltaTime = 0, nowTime = 0;
  int frames = 0, updates = 0;

  game = new Game();

	while(isRunning){

    nowTime = Time::GetTime();
    deltaTime += (nowTime - lastTime) / frameTime;
    lastTime = nowTime;

    while (deltaTime >= 1.0){
        game->OnInput(keyboard);
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

    if(!window->IsRunning()){
      Stop();
    }
	}


}

void Core::Update(){
  game->OnUpdate();
  keyboard->Update();
  window->Update();
}

void Core::Render(){
  game->OnRender();
}

void Core::Destroy(){
  game->OnDestroy();
  window->Close();
}

