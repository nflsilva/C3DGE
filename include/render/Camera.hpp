#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "tools/Log.hpp"

class Camera {
  private:
    glm::vec3 position;
    glm::vec3 forward;
    glm::vec3 up;
    glm::mat4 transformation;
  
    void UpdateTransformationMatrix();

  public:
    Camera(glm::vec3 position, glm::vec3 forward, glm::vec3 up);
    ~Camera();

    void SetPosition(glm::vec3 position);
    void Move(glm::vec3 direction, float delta);
    void Rotate(float angle, glm::vec3 axis);

    glm::vec3 Up();
    glm::vec3 Left();
    glm::vec3 Forward();

    glm::mat4 GetTransformationMatrix();

};

#endif