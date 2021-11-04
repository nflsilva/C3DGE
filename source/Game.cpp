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

  Resources::MeshData md = Resources::LoadMeshData("teddy.obj");

  trComponent = new RenderComponent();
  trComponent->CreateGeometry(md.vertices, md.indices);

  triangle = new GameObject();
  triangle->renderComponents.push_front(trComponent);

  engine->AddGameObject(triangle);

}

void Game::OnInput(){

}

void Game::OnUpdate(){

}

void Game::OnRender(){
  f += 0.025;

  glm::mat4 t = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -25.0f));
  glm::mat4 r = glm::rotate(t, (float)(f * M_PI * 10.0 / 180), glm::vec3(0.0f, 1.0f, 0.0f));
  //glm::mat4 s = glm::scale(r, glm::vec3(sin(f)));

  triangle->renderComponents.front()->transform = r;
}

void Game::OnDestroy(){
  delete(triangle);
}
