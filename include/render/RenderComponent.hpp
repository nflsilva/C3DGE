#ifndef RENDER_COMPONENT_HPP
#define RENDER_COMPONENT_HPP

#include <glm/ext/matrix_float4x4.hpp>
#include "render/Mesh.hpp"
#include "render/Texture.hpp"

class RenderComponent {
  public:
    glm::mat4 transform;
    Mesh* geometry;
    Texture* texture;
    
  public:
    RenderComponent();
    ~RenderComponent();
    void CreateGeometry(
      std::vector<float> positions,
      std::vector<float> textureCoordinates, 
      std::vector<float> colors,
      std::vector<float> normals, 
      std::vector<int> indices);
    void CreateTexture(std::string fileName);
};

#endif