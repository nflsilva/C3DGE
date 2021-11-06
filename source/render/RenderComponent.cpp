#include "render/RenderComponent.hpp"

RenderComponent::RenderComponent() : geometry(NULL), texture(NULL) { 

}

RenderComponent::~RenderComponent(){
  if(geometry) delete(geometry);
  if(texture) delete(texture);
}

void RenderComponent::CreateGeometry(
  std::vector<float> positions,
  std::vector<float> textureCoordinates, 
  std::vector<float> colors,
  std::vector<float> normals, 
  std::vector<int> indices){

  geometry = new Mesh(positions, textureCoordinates, colors, normals, indices);
}

void RenderComponent::CreateTexture(std::string fileName){
  texture = new Texture(fileName);
}