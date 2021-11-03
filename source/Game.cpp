#include "Game.hpp"
#include "tools/Log.hpp"

#include <glm/ext/vector_float3.hpp> 

Game::Game(){}
Game::~Game(){};

void Game::OnStart(){

}

void Game::OnInput(Keyboard* keyboard, Mouse* mouse){

  if(keyboard->GetKey(87)){
    Log::D("Press W");
  }
  else if(keyboard->GetKeyDown(87)){
    Log::D("Down W");
  }
  else if(keyboard->GetKeyUp(87)){
    Log::D("Up W");
  }

  if(mouse->GetButton(1)){
    Log::D("Press M1");
    Log::D("Mouse " + std::to_string(mouse->GetX()));
  }
  else if(mouse->GetButtonDown(0)){
    Log::D("Down M0");
  }
  else if(mouse->GetButtonUp(0)){
    Log::D("Up M0");
  }

}

void Game::OnUpdate(){


}

void Game::OnRender(){

}

void Game::OnDestroy(){

}
