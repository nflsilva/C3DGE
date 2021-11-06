#include "render/Camera.hpp"
#include <glm/gtx/transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 forward, glm::vec3 up) : position(position), forward(forward), up(up) {
  up = glm::normalize(up);
  forward = glm::normalize(forward);

  lockAt = glm::normalize(position + forward);

  UpdateTransformationMatrix();
}

Camera::~Camera(){}

void Camera::UpdateTransformationMatrix(){
  transformation = glm::lookAt(position, position + forward, up);
}

glm::vec3 Camera::GetPosition(){
  return position;
}

void Camera::SetPosition(glm::vec3 position){
  this->position = position;
}

void Camera::TransformPosition(glm::mat4 transform){
  glm::vec4 new_position = transform * glm::vec4(position.x, position.y, position.z, 1.0);
  position.x = new_position.x;
  position.y = new_position.y;
  position.z = new_position.z;
}

void Camera::Move(glm::vec3 direction, float delta){
  position += (direction * delta);
  UpdateTransformationMatrix();
}

void Camera::RotateSelf(float angle, glm::vec3 axis){
  glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(angle), axis);
  forward = glm::vec3(rotationMatrix * glm::vec4(forward, 1.0));
  forward = glm::normalize(forward);
  UpdateTransformationMatrix();
}

void Camera::RotateAround(float angle, glm::vec3 axis){
  glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(angle), axis);
  up = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(up, 1.0)));
  forward = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(forward, 1.0)));
  TransformPosition(rotationMatrix);
  UpdateTransformationMatrix();
}

glm::mat4 Camera::GetTransformationMatrix(){
  return transformation;
}

glm::vec3 Camera::Up(){
  return up;
}

glm::vec3 Camera::Left(){
  glm::vec3 left = glm::cross(up, forward);
  return glm::normalize(left); 
}

glm::vec3 Camera::Forward(){
  return forward;
}
