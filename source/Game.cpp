#include "Game.hpp"
#include "tools/Log.hpp"

Game::Game(){}
Game::~Game(){};

void Game::OnStart(){

}

void Game::OnInput(Keyboard* keyboard){

  if(keyboard->GetKey(87)){
    Log::D("Press W");
  }
  else if(keyboard->GetKeyDown(87)){
    Log::D("Down W");
  }
  else if(keyboard->GetKeyUp(87)){
    Log::D("Up W");
  }

}

void Game::OnUpdate(){

}

void Game::OnRender(){

}

void Game::OnDestroy(){

}
