#include "render/RenderEngine.hpp"
#include "tools/Log.hpp"
#include "tools/Time.hpp"

RenderEngine::RenderEngine(int width, int height) : width(width), height(height){

  fov = 70.0f;
  zNear = 0.1f;
  zFar = 500.f;
  float ar = (float)width / (float)height;
  projectionMatrix = glm::perspective(glm::radians(fov), ar, zNear, zFar);

  camera = new Camera(glm::vec3(0, 15, 15), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
  cameraSpeed = glm::vec3(0);
  lightDirection = glm::vec4(0.0, -1.0, 0.0, 1.0);
}

RenderEngine::~RenderEngine(){
  std::unordered_map<int, ShaderProgram*>::iterator it = shaders.begin();
  while (it != shaders.end()){ delete(it->second); it++; }
  delete(camera);
}

void RenderEngine::Init(){

  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    Log::E(std::string((char*)glewGetErrorString(err)));
    exit(1);
  }
  Log::I("GLEW version " + std::string((char*)glewGetString(GLEW_VERSION)));

  CreateShaders();

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glViewport(0, 0, width, height);

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void RenderEngine::CreateShaders() {
	ShaderProgram* sp = new ShaderProgram();
  sp->AddVertexShader("toon/Vertex.glsl");
  sp->AddFragmentShader("toon/Fragment.glsl");
  shaders[sp->GetProgram()] = sp;

  sp->AddUniform("in_transform");
  sp->AddUniform("in_lightDirection");
  sp->AddUniform("in_cameraPosition");
  sp->Bind();
}

void RenderEngine::Render(std::list<RenderComponent*> components){
  for(auto o : components){
    shaders[1]->SetUniformMatrix4f("in_transform", projectionMatrix * camera->GetTransformationMatrix() * o->transform);
    shaders[1]->SetUniformVector3f("in_lightDirection", glm::vec3(lightDirection.x, lightDirection.y, lightDirection.z));
    shaders[1]->SetUniformVector3f("in_cameraPosition", glm::vec3(camera->GetPosition().x, camera->GetPosition().y, camera->GetPosition().z));
    if(o->texture)
      o->texture->Bind(0);
    o->geometry->Draw();
  }
}

void RenderEngine::Update(){

  if(cameraSpeed.x != 0){
    camera->Move(camera->Left(), cameraSpeed.x * Time::GetDelta());
    cameraSpeed.x = (int)cameraSpeed.x / 1.05f;
  }

  if(cameraSpeed.y != 0){
    camera->Move(camera->Up(), cameraSpeed.y * Time::GetDelta());
    cameraSpeed.y = (int)cameraSpeed.y / 1.05f;
  }

  if(cameraSpeed.z != 0){
    camera->Move(camera->Forward(), cameraSpeed.z * Time::GetDelta());
    cameraSpeed.z = (int)cameraSpeed.z / 1.05f;
  }

  glm::mat4 rotation = glm::rotate(glm::mat4(1), 0.01f, glm::vec3(0.0, 0.0, 1.0));
  lightDirection = rotation * lightDirection;
}

void RenderEngine::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void RenderEngine::MoveCameraLeft(){
  cameraSpeed.x += 5.0f;
}

void RenderEngine::MoveCameraRight(){
  cameraSpeed.x -= 5.0f;
};

void RenderEngine::MoveCameraFoward(){
  cameraSpeed.z += 15.0f;
}

void RenderEngine::MoveCameraBackwards(){
  cameraSpeed.z -= 15.0f;
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

