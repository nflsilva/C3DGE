#include "render/BaseCamera.hpp"

void BaseCamera::TransformPosition(glm::mat4 transform){
  glm::vec4 new_position = transform * glm::vec4(position.x, position.y, position.z, 1.0);
  position.x = new_position.x;
  position.y = new_position.y;
  position.z = new_position.z;
}
void BaseCamera::BaseCamera::UpdateViewMatrix(){
  viewMatrix = glm::lookAt(position, position + forward, up);
}

BaseCamera::BaseCamera(glm::vec3 position, glm::vec3 forward, glm::vec3 up) : position(position), forward(forward), up(up) {
  up = glm::normalize(up);
  forward = glm::normalize(forward);
  lockAt = glm::normalize(position + forward);
  UpdateViewMatrix();
}
BaseCamera::~BaseCamera(){}
glm::vec3 BaseCamera::GetPosition(){
  return position;
}
glm::mat4 BaseCamera::GetViewMatrix(){
  return viewMatrix;
}
glm::vec3 BaseCamera::GetUp(){
  return up;
}
glm::vec3 BaseCamera::GetLeft(){
  glm::vec3 left = glm::cross(up, forward);
  return glm::normalize(left); 
}
glm::vec3 BaseCamera::GetForward(){
  return forward;
}

void BaseCamera::SetPosition(glm::vec3 newPosition){
  position = newPosition;
}

void BaseCamera::Move(glm::vec3 direction, float delta){
  position += (direction * delta);
  UpdateViewMatrix();
}
void BaseCamera::RotateSelf(float angle, glm::vec3 axis){
  glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(angle), axis);
  forward = glm::vec3(rotationMatrix * glm::vec4(forward, 1.0));
  forward = glm::normalize(forward);
  UpdateViewMatrix();
}
void BaseCamera::RotateAround(float angle, glm::vec3 axis){
  glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(angle), axis);
  up = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(up, 1.0)));
  forward = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(forward, 1.0)));
  TransformPosition(rotationMatrix);
  UpdateViewMatrix();
}

void BaseCamera::Update(float elapsedTime, InputState input){
  //Does nothing
}