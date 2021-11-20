#include "render/RenderEngine.hpp"
#include "tools/Log.hpp"
#include "tools/Time.hpp"

RenderEngine::RenderEngine(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {
  /*
  camera = new Camera(glm::vec3(0, 1, 1), glm::vec3(0, -0.75, -1), glm::vec3(0, 1, 0));
  cameraSpeed = glm::vec3(0);
  lightDirection = glm::vec4(0.0, -1.0, 0.0, 1.0);
  */
}

RenderEngine::~RenderEngine(){

}

void RenderEngine::Init(){

  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    Log::E(std::string((char*)glewGetErrorString(err)));
    exit(1);
  }
  Log::I("GLEW version " + std::string((char*)glewGetString(GLEW_VERSION)));

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);

}

void RenderEngine::Render(){

  /*for(auto o : components){
    shaders[0]->SetUniformMatrix4f("in_transform", projectionMatrix * camera->GetViewMatrix() * o->transform);
    shaders[0]->SetUniformVector3f("in_lightDirection", glm::vec3(lightDirection.x, lightDirection.y, lightDirection.z));
    shaders[0]->SetUniformVector3f("in_cameraPosition", glm::vec3(camera->GetPosition().x, camera->GetPosition().y, camera->GetPosition().z));
    if(o->texture)
      o->texture->Bind(0);
    o->geometry->Draw();
  }*/

}

void RenderEngine::Update(){
  if(camera) camera->Update();

}

void RenderEngine::Input(InputState input){
  if(camera) camera->Input(input);

}
void RenderEngine::SetCamera(BaseCamera* camera) {
  this->camera = camera;
}

void RenderEngine::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

/*
void RenderEngine::MoveCameraLeft(){
  cameraSpeed.x += 5.0f;
}

void RenderEngine::MoveCameraRight(){
  cameraSpeed.x -= 5.0f;
};

void RenderEngine::MoveCameraFoward(){
  cameraSpeed.z += 5.0f;
}

void RenderEngine::MoveCameraBackwards(){
  cameraSpeed.z -= 5.0f;
};

void RenderEngine::MoveCameraUp(){
  cameraSpeed.y += 5.0f;
}

void RenderEngine::MoveCameraDown(){
  cameraSpeed.y -= 5.0f;
};

void RenderEngine::RotateSceneVerticalAxis(float angle){
  camera->RotateAround(angle * 2 * Time::GetDelta(), camera->Up());
}

void RenderEngine::RotateSceneHorizontalAxis(float angle){
  camera->RotateAround(-angle * 2 * Time::GetDelta(), camera->Left());
}
*/
