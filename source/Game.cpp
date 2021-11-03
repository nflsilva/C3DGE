#include "Game.hpp"
#include "tools/Log.hpp"

Game::Game(CoreEngine* engine) : engine(engine) {}
Game::~Game(){};

void Game::OnStart(){
  RenderComponent * trComponent = new RenderComponent();
  trComponent->CreateGeometry(vertexes, 3);

  triangle = new GameObject();
  triangle->renderComponents.push_front(trComponent);

  engine->AddGameObject(triangle);
}

void Game::OnInput(){

}

void Game::OnUpdate(){

}

void Game::OnRender(){

}

void Game::OnDestroy(){

}
