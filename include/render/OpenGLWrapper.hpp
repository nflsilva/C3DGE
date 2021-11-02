#ifndef OPENGLWRAPPER_HPP
#define OPENGLWRAPPER_HPP

#include <GL/glew.h>
#include "render/iGraphicsAPI.hpp"

class OpenGLWrapper : public iGraphicsAPI {
  private:
    int width;
    int height;

  public:
    OpenGLWrapper(int width, int height);
    void Init();
    void ClearScreen();
};

#endif