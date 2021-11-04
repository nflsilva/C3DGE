#include "render/RenderEngine.hpp"
#include "tools/Log.hpp"

RenderEngine::RenderEngine(int width, int height) : width(width), height(height){}

RenderEngine::~RenderEngine(){
  std::unordered_map<int, ShaderProgram*>::iterator it = shaders.begin();
  while (it != shaders.end()){ delete(it->second); it++; }
}

void RenderEngine::Init(){

  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    Log::E(std::string((char*)glewGetErrorString(err)));
    exit(1);
  }
  Log::D("Using GLEW " + std::string((char*)glewGetString(GLEW_VERSION)));

  CreateShaders();

  glEnable(GL_DEPTH_TEST);
  glViewport(0, 0, width, height);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  fov = 45.0f;
  zNear = 0.1f;
  zFar = 100.f;
  float ar = (float)width / (float)height;
  projectionMatrix = glm::perspective(glm::radians(fov), ar, zNear, zFar);

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
  ClearScreen();
  for(auto o : components){
    o->geometry->Draw();
    shaders[1]->SetUniformMatrix4f("tranform", projectionMatrix * o->transform);
  }
}

void RenderEngine::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}