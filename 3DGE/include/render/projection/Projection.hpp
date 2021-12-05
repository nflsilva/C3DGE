#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include <glm/ext/matrix_float4x4.hpp>

class Projection {
  public:
    virtual glm::mat4 GetProjectionMatrix() = 0;
};

#endif