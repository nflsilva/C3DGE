#include "render/BaseModel.hpp"

BaseModel::BaseModel(Mesh* mesh, Texture* texture, Shader* shader) : mesh(mesh), texture(texture), shader(shader) {

}

BaseModel::~BaseModel(){};

Mesh* BaseModel::GetMesh(){
  return mesh;
}
Texture* BaseModel::GetTexture(){
  return texture;
}
Shader* BaseModel::GetShader(){
  return shader;
}