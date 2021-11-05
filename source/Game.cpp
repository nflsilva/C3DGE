#include "Game.hpp"
#include "tools/Log.hpp"

#include "tools/Resources.hpp"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp>

Game::Game(CoreEngine* engine) : engine(engine) {}
Game::~Game(){};

void Game::OnStart(){
  Resources::MeshData boardData = Resources::LoadMeshData("cube.obj");
  
  Resources::MeshData cowData = Resources::LoadMeshData("cow.obj");
  Resources::MeshData teddyData = Resources::LoadMeshData("teddy.obj");
  Resources::MeshData teapotData = Resources::LoadMeshData("teapot.obj");

  cow = GameObject::Builder()
          .AddGeometry(cowData.vertices, cowData.indices)
          .Build();

  teddy = GameObject::Builder()
          .AddGeometry(teddyData.vertices, teddyData.indices)
          .Build();

  teapot = GameObject::Builder()
          .AddGeometry(teapotData.vertices, teapotData.indices)
          .Build();

  std::vector<Vertex> positions = {
    Vertex( 0.5f,  0.5f, -1.0f, 2.0f, 2.0f),
    Vertex( 0.5f, -0.5f, -1.0f, 2.0f, 0.0f),
    Vertex(-0.5f, -0.5f, -1.0f, 0.0f, 0.0f),
    Vertex(-0.5f,  0.5f, -1.0f, 0.0f, 2.0f),
  };

  std::vector<int> indices = {
    0, 1, 3,
    1, 2, 3
  };

  board = GameObject::Builder()
          .AddGeometry(boardData.vertices, boardData.indices)
          .AddTexture("grass.tga")
          .Build();

  engine->AddGameObject(cow);
  engine->AddGameObject(teddy);
  engine->AddGameObject(teapot);
  engine->AddGameObject(board);

}

void Game::OnInput(InputState input){

  if(InputState::ContainsKey(&input.isDownKeys, 65) || InputState::ContainsKey(&input.isCurrentKey, 65)){
    engine->MoveCameraToLeft();
  }
  if(InputState::ContainsKey(&input.isDownKeys, 68) || InputState::ContainsKey(&input.isCurrentKey, 68)){
    engine->MoveCameraToRight();
  }
  if(InputState::ContainsKey(&input.isDownKeys, 87) || InputState::ContainsKey(&input.isCurrentKey, 87)){
    engine->MoveCameraForward();
  }
  if(InputState::ContainsKey(&input.isDownKeys, 83) || InputState::ContainsKey(&input.isCurrentKey, 83)){
    engine->MoveCameraBackwards();
  }
  if(InputState::ContainsKey(&input.isDownKeys, 54) || InputState::ContainsKey(&input.isCurrentKey, 54)){
    engine->RotateCameraLeft();
  }

}

void Game::OnUpdate(){

}

void Game::OnRender(){
  f += 0.025;
  //glm::mat4 s = glm::scale(r, glm::vec3(sin(f)));

  glm::mat4 tt = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -15.0f));
  glm::mat4 tr = glm::rotate(tt, (float)(f * M_PI * 10.0 / 180), glm::vec3(1.0f, 1.0f, 1.0f));
  teddy->renderComponents.front()->transform = tr;

  glm::mat4 ct = glm::translate(glm::mat4(1.0f), glm::vec3(-2.5f, -1.0f, -5.0f));
  glm::mat4 cr = glm::rotate(ct, (float)(2 * f * M_PI * 10.0 / 180), glm::vec3(1.0f, 1.0f, 0.0f));
  cow->renderComponents.front()->transform = cr;

  glm::mat4 pt = glm::translate(glm::mat4(1.0f), glm::vec3(2.5f, 1.0f, -5.0f));
  glm::mat4 pr = glm::rotate(pt, (float)(4 * f * M_PI * 10.0 / 180), glm::vec3(0.0f, 1.0f, 1.0f));
  teapot->renderComponents.front()->transform = pr;

  glm::mat4 bt = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f));
  glm::mat4 br = glm::rotate(bt, (float)(4 * f * M_PI * 10.0 / 180), glm::vec3(0.0f, 1.0f, 1.0f));
  board->renderComponents.front()->transform = br;
}

void Game::OnDestroy(){
  delete(teddy);
  delete(cow);
  delete(teapot);
  delete(board);
}
