#include "render/RenderEngine.hpp"
#include "tools/Log.hpp"

float angle = 0;

RenderEngine::RenderEngine(int width, int height) : width(width), height(height){

  fov = 70.0f;
  zNear = 0.1f;
  zFar = 100.f;
  float ar = (float)width / (float)height;
  projectionMatrix = glm::perspective(glm::radians(fov), ar, zNear, zFar);

  camera = new Camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
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
  glViewport(0, 0, width, height);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void RenderEngine::CreateShaders() {
	ShaderProgram* sp = new ShaderProgram();
  sp->AddVertexShader("GenericVertex.glsl");
  sp->AddFragmentShader("GenericFragment.glsl");
  shaders[sp->GetProgram()] = sp;

  sp->AddUniform("tranform");
  sp->Bind();
}

void RenderEngine::Render(std::list<RenderComponent*> components){
  for(auto o : components){
    shaders[1]->SetUniformMatrix4f("tranform", projectionMatrix * camera->GetTransformationMatrix() * o->transform);
    o->geometry->Draw();
  }
}

void RenderEngine::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void RenderEngine::MoveCameraLeft(){
  camera->Move(camera->Left(), 0.5f);
  //camera->Rotate(0.5, glm::vec3(0.0f, 1.0f, 0.0f));
}

void RenderEngine::MoveCameraRight(){
  camera->Move(camera->Left(), -0.5f);
};

void RenderEngine::MoveCameraFoward(){
  camera->Move(camera->Forward(), 0.5f);
}

void RenderEngine::MoveCameraBackwards(){
  camera->Move(camera->Forward(), -0.5f);
};

void RenderEngine::RotateCameraLeft(){
  camera->Rotate(10.0f, glm::vec3(0, 1, 0));
}