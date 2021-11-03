#ifndef RENDER_ENGINE_HPP
#define RENDER_ENGINE_HPP

#include <GL/glew.h>
#include "render/RenderComponent.hpp"

class RenderEngine {
  private:
    int width;
    int height;

  public:
    RenderEngine(int width, int height);
    void Init();
    void Render(std::list<RenderComponent*> components);
    void ClearScreen();
};

#endif