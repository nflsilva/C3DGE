#include "render/RenderComponent.hpp"

RenderComponent::RenderComponent() : geometry(NULL) { 

}

void RenderComponent::CreateGeometry(Vertex* vertices, int size){
  geometry = new Mesh(vertices, size);
}