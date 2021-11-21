#include "core/GameObject.hpp"


GameObject::GameObject(BaseModel* model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : 
model(model), position(position), rotation(rotation), scale(scale) {
  UpdateModelMatrix();
}

GameObject::~GameObject(){
  delete(model);
}

void GameObject::UpdateModelMatrix(){
  modelMatrix = glm::translate(glm::mat4(1.0F), position);
  modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
  modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
  modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
  modelMatrix = glm::scale(modelMatrix, scale);
}

BaseModel* GameObject::GetModel(){
  return model;
}

glm::mat4 GameObject::GetModelMatrix(){
  return modelMatrix;
}

void GameObject::SetPosition(glm::vec3 newPosition){
  position = newPosition;
}
void GameObject::Move(glm::vec3 delta){
  position += delta;
}
void GameObject::Rotate(glm::vec3 delta){
  rotation += delta;
}
void GameObject::Scale(glm::vec3 delta){
  scale += delta;
}

void GameObject::Update(float elapsedTime, InputState input){
  //Does nothing
}