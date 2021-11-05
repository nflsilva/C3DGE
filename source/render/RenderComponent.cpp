#include "render/RenderComponent.hpp"

RenderComponent::RenderComponent() : geometry(NULL), texture(NULL) { 

}

RenderComponent::~RenderComponent(){
  if(geometry) delete(geometry);
  if(texture) delete(texture);
}

void RenderComponent::CreateGeometry(std::vector<Vertex> vertices,std::vector<int> indices){
  geometry = new Mesh(vertices, indices);
}

void RenderComponent::CreateTexture(std::string fileName){
  texture = new Texture(fileName);
}