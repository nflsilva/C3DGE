#pragma once

#include <glm/mat4x4.hpp>

#include "render/BaseCamera.hpp"


class MovingCamera : public BaseCamera {
  private:
    glm::vec3 speed;

  public:
    MovingCamera(glm::vec3 position, glm::vec3 forward, glm::vec3 up) : BaseCamera(position, forward, up), speed(glm::vec3(0.0F)) {
    }

    void Update(float elapsedTime, InputState input) override {
      
      if(input.IsKeyPressed(InputState::KEY_W)){ // W
        speed.y += 5.0F;
        UpdateViewMatrix();
      }
      else if(input.IsKeyPressed(InputState::KEY_S)){ // S
        speed.y -= 5.0F;
        UpdateViewMatrix();
      }

      if(input.IsKeyPressed(InputState::KEY_A)){ // A
        speed.x += 5.0F;
        UpdateViewMatrix();
      }
      else if(input.IsKeyPressed(InputState::KEY_D)){ // D
        speed.x -= 5.0F;
        UpdateViewMatrix();
      }

      if(input.DidYScrollUp()){
        speed.z += 5.0F;
        UpdateViewMatrix();
      }
      else if(input.DidYScrollDown()){
        speed.z -= 5.0F;
        UpdateViewMatrix();
      }

      if(speed.x != 0){
        Move(GetLeft(), speed.x * elapsedTime);
        speed.x = (int)speed.x / 1.05f;
      }

      if(speed.y != 0){
        Move(up, speed.y * elapsedTime);
        speed.y = (int)speed.y / 1.05f;
      }

      if(speed.z != 0){
        Move(forward, speed.z * elapsedTime);
        speed.z = (int)speed.z / 1.05f;
      }
    
    }

};