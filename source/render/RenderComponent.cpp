#include "render/RenderComponent.hpp"

RenderComponent::RenderComponent() : geometry(NULL) { 

}

void RenderComponent::CreateGeometry(std::vector<Vertex> vertices,std::vector<int> indices){
  geometry = new Mesh(vertices, indices);
}