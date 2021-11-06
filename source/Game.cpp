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
  Resources::MeshData cubeData = Resources::LoadMeshData("dog.obj");



  cube = GameObject::Builder()
          .AddGeometry(cubeData)
          .AddTexture("grass.tga")
          .Build();

  engine->AddGameObject(cube);
}

void Game::OnInput(InputState input){

  if(input.IsKeyPressed(65)){ // A
    engine->MoveCameraToLeft();
  }
  if(input.IsKeyPressed(68)){ // D
    engine->MoveCameraToRight();
  }
  if(input.IsKeyPressed(87)){ // W
    engine->MoveCameraUp();
  }
  if(input.IsKeyPressed(83)){ // S
    engine->MoveCameraDown();
  }

  if(input.IsMousePressed(0)){
    engine->RotateSceneVerticalAxis(input.GetDragDeltaX());
    engine->RotateSceneHorizontalAxis(input.GetDragDeltaY());
    Log::D(std::to_string(input.GetDragDeltaX()) + " : " + std::to_string(input.GetDragDeltaY()));
  }

  if(input.DidYScrollUp()){
    engine->MoveCameraForward();
  }else if(input.DidYScrollDown()){
    engine->MoveCameraBackwards();
  }

}

void Game::OnUpdate(){

}

void Game::OnRender(){
  f += 0.025;
  //glm::mat4 s = glm::scale(r, glm::vec3(sin(f)));

  //glm::mat4 bt = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, .0f, -5.0f));
  //glm::mat4 br = glm::rotate(bt, (float)(1 * f * M_PI * 10.0 / 180), glm::vec3(1.0f, 1.0f, 0.0f));
  cube->renderComponents.front()->transform = glm::mat4(1.0f);
}

void Game::OnDestroy(){
  delete(cube);
}
