#include "render/OpenGLWrapper.hpp"
#include "tools/Log.hpp"

OpenGLWrapper::OpenGLWrapper(int width, int height) : width(width), height(height){}

void OpenGLWrapper::Init(){

  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    Log::E(std::string((char*)glewGetErrorString(err)));
    exit(1);
  }
  Log::D("Using GLEW " + std::string((char*)glewGetString(GLEW_VERSION)));

  glEnable(GL_DEPTH_TEST);
  glViewport(0, 0, width, height);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void OpenGLWrapper::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
}