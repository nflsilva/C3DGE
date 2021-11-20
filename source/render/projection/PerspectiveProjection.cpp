#include "render/projection/PerspectiveProjection.hpp"

PerspectiveProjection::PerspectiveProjection(float width, float height, float fov, float zNear, float zFar) {
  float ar = width / height;
  projectionMatrix = glm::perspective(glm::radians(fov), ar, zNear, zFar);
};

PerspectiveProjection::~PerspectiveProjection(){};

glm::mat4 PerspectiveProjection::GetProjection() {
  return projectionMatrix;
};
