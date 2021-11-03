#include "render/Mesh.hpp"
#include "Game.hpp"
#include "tools/Log.hpp"

#include <glm/ext/vector_float3.hpp> 
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

Mesh* mesh;
Vertex vertexes[] = {
  Vertex(-1, -1, 0),
  Vertex(0, 1, 0),
  Vertex(1, -1, 0),
};

Game::Game(){}
Game::~Game(){};

void Game::OnStart(){


  mesh = new Mesh(vertexes, 3);
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
  mesh->Draw();
}

void Game::OnDestroy(){

}
