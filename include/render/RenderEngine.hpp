#ifndef RENDER_ENGINE_HPP
#define RENDER_ENGINE_HPP

#include <GL/glew.h>

class RenderEngine {
  private:
    int width;
    int height;

  public:
    RenderEngine(int width, int height);
    void Init();
    void ClearScreen();
};

#endif