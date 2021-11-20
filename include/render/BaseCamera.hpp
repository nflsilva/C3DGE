#ifndef BASE_CAMERA_HPP
#define BASE_CAMERA_HPP

#include <string>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "tools/Log.hpp"
#include "ui/InputState.hpp"

class BaseCamera {
  private:
    glm::vec3 position;
    glm::vec3 lockAt;
    glm::vec3 forward;
    glm::vec3 up;
    glm::mat4 viewMatrix;
  
    void TransformPosition(glm::mat4 transform){
      glm::vec4 new_position = transform * glm::vec4(position.x, position.y, position.z, 1.0);
      position.x = new_position.x;
      position.y = new_position.y;
      position.z = new_position.z;
    }
    void UpdateViewMatrix(){
      position.y = std::max(position.y, 0.0f);
      viewMatrix = glm::lookAt(position, position + forward, up);
    }
    
  public:
    BaseCamera(glm::vec3 position, glm::vec3 forward, glm::vec3 up) : position(position), forward(forward), up(up) {
      up = glm::normalize(up);
      forward = glm::normalize(forward);
      lockAt = glm::normalize(position + forward);
      UpdateViewMatrix();
    }
    ~BaseCamera(){
      
    }



    glm::vec3 GetPosition(){
      return position;
    }
    glm::mat4 GetViewMatrix(){
      return viewMatrix;
    }
    glm::vec3 GetUp(){
      return up;
    }
    glm::vec3 GetLeft(){
      glm::vec3 left = glm::cross(up, forward);
      return glm::normalize(left); 
    }
    glm::vec3 GetForward(){
      return forward;
    }

    void SetPosition(glm::vec3 position){
      this->position = position;
    }

    void Move(glm::vec3 direction, float delta){
      position += (direction * delta);
      UpdateViewMatrix();
    }
    void RotateSelf(float angle, glm::vec3 axis){
      glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(angle), axis);
      forward = glm::vec3(rotationMatrix * glm::vec4(forward, 1.0));
      forward = glm::normalize(forward);
      UpdateViewMatrix();
    }
    void RotateAround(float angle, glm::vec3 axis){
      glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(angle), axis);
      up = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(up, 1.0)));
      forward = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(forward, 1.0)));
      TransformPosition(rotationMatrix);
      UpdateViewMatrix();
    }

    void Update(){};
    void Input(InputState input){};

};

#endif