#include "render/Camera.hpp"
#include <glm/gtx/transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 forward, glm::vec3 up) : position(position), forward(forward), up(up) {
  up = glm::normalize(up);
  forward = glm::normalize(forward);

  UpdateTransformationMatrix();
}

Camera::~Camera(){}

void Camera::UpdateTransformationMatrix(){
  transformation = glm::lookAt(position, position + forward, up);
}

void Camera::SetPosition(glm::vec3 position){
  this->position = position;
}

void Camera::Move(glm::vec3 direction, float delta){
  position += (direction * delta);
  UpdateTransformationMatrix();
  Log::D("[" + std::to_string(position.x) + " " + std::to_string(position.y) + " " + std::to_string(position.z));
}

void Camera::Rotate(float angle, glm::vec3 axis){
  glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(angle), axis);
  //up = glm::vec3(rotationMatrix * glm::vec4(up, 1.0));
  //up = glm::normalize(up);

  forward = glm::vec3(rotationMatrix * glm::vec4(forward, 1.0));
  forward = glm::normalize(forward);

  UpdateTransformationMatrix();
  Log::D("[" + std::to_string(forward.x) + " " + std::to_string(forward.y) + " " + std::to_string(forward.z));
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
