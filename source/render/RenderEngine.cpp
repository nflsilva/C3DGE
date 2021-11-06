#include "render/RenderEngine.hpp"
#include "tools/Log.hpp"
#include "tools/Time.hpp"

float angle = 0;

RenderEngine::RenderEngine(int width, int height) : width(width), height(height){

  fov = 70.0f;
  zNear = 0.1f;
  zFar = 100.f;
  float ar = (float)width / (float)height;
  projectionMatrix = glm::perspective(glm::radians(fov), ar, zNear, zFar);

  camera = new Camera(glm::vec3(0, 0, 5), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
  cameraSpeed = glm::vec3(0);
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
  sp->AddVertexShader("generic/Vertex.glsl");
  sp->AddFragmentShader("generic/Fragment.glsl");
  shaders[sp->GetProgram()] = sp;

  sp->AddUniform("tranform");
  sp->Bind();
}

void RenderEngine::Render(std::list<RenderComponent*> components){
  for(auto o : components){
    shaders[1]->SetUniformMatrix4f("in_transform", projectionMatrix * camera->GetTransformationMatrix() * o->transform);
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
  camera->RotateAround(angle * Time::GetDelta(), camera->Up());
}

void RenderEngine::RotateSceneHorizontalAxis(float angle){
  camera->RotateAround(-angle * Time::GetDelta(), camera->Left());
}

