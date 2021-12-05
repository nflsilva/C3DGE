#ifndef BASE_CAMERA_HPP
#define BASE_CAMERA_HPP

#include <string>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "tools/Log.hpp"
#include "ui/InputState.hpp"

class BaseCamera {
  protected:
    glm::vec3 position;
    glm::vec3 lockAt;
    glm::vec3 forward;
    glm::vec3 up;
    glm::mat4 viewMatrix;
  
    void TransformPosition(glm::mat4 transform);
    void UpdateViewMatrix();
    
  public:
    BaseCamera(glm::vec3 position, glm::vec3 forward, glm::vec3 up);
    virtual ~BaseCamera();
    glm::vec3 GetPosition();
    glm::mat4 GetViewMatrix();
    glm::vec3 GetUp();
    glm::vec3 GetLeft();
    glm::vec3 GetForward();

    void SetPosition(glm::vec3 position);
    void Move(glm::vec3 direction, float delta);
    void RotateSelf(float angle, glm::vec3 axis);
    void RotateAround(float angle, glm::vec3 axis);

    virtual void Update(float elapsedTime, InputState input);
};

#endif