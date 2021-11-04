#include "render/RenderComponent.hpp"

RenderComponent::RenderComponent() : geometry(NULL) { 

}

RenderComponent::~RenderComponent(){
  if(geometry) delete(geometry);
}

void RenderComponent::CreateGeometry(std::vector<Vertex> vertices,std::vector<int> indices){
  geometry = new Mesh(vertices, indices);
}