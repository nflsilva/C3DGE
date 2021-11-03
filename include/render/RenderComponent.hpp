#ifndef RENDER_COMPONENT_HPP
#define RENDER_COMPONENT_HPP

#include "render/Mesh.hpp"

class RenderComponent {

  public:
    Mesh* geometry;
  
  public:
    RenderComponent();
    void CreateGeometry(Vertex* vertices, int size);

};

#endif