#ifndef RENDER_COMPONENT_HPP
#define RENDER_COMPONENT_HPP

#include <glm/ext/matrix_float4x4.hpp>
#include "render/Mesh.hpp"

class RenderComponent {
  public:
    Mesh* geometry;
    glm::mat4 transform;
  
  public:
    RenderComponent();
    ~RenderComponent();
    void CreateGeometry(std::vector<Vertex> vertices,std::vector<int> indices);
};

#endif