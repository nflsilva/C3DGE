#include "render/model/BaseModel.hpp"

BaseModel::BaseModel(Mesh* mesh, Texture* texture, Shader* shader) : mesh(mesh), texture(texture), shader(shader) {}
BaseModel::~BaseModel(){
  if(mesh) delete(mesh);
  if(texture) delete(texture);
  if(shader) delete(shader);
};

Mesh* BaseModel::GetMesh(){
  return mesh;
}
Texture* BaseModel::GetTexture(){
  return texture;
}
Shader* BaseModel::GetShader(){
  return shader;
}