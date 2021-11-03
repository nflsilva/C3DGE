#include "render/RenderEngine.hpp"
#include "render/ShaderProgram.hpp"
#include "tools/Log.hpp"

RenderEngine::RenderEngine(int width, int height) : width(width), height(height){}

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

}

void RenderEngine::CreateShaders() {
	ShaderProgram sp;
  sp.AddVertexShader("GenericVertex.glsl");
  sp.AddFragmentShader("GenericFragment.glsl");

  sp.Bind();
}

void RenderEngine::Render(std::list<RenderComponent*> components){
  for(auto o : components)
    o->geometry->Draw();
}

void RenderEngine::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
}