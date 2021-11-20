#ifndef PERSPECTIVE_PROJECTION_HPP
#define PERSPECTIVE_PROJECTION_HPP

#include <glm/gtc/matrix_transform.hpp>
#include "render/projection/Projection.hpp"


class PerspectiveProjection : public Projection {

  private:
    float width;
    float height;
    float fov;
    float zNear;
    float zFar;
    glm::mat4 projectionMatrix;
    
  public:
    PerspectiveProjection(float width, float height, float fov, float zNear, float zFar);
    ~PerspectiveProjection();
    glm::mat4 GetProjection();
};

#endif