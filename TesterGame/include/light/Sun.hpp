#pragma once

#include <glm/gtc/matrix_transform.hpp>

#include "render/light/DirectionalLight.hpp"

class Sun : public DirectionalLight {
  private:
    float phase;

  public:
    Sun() : DirectionalLight(glm::vec3(0, -1, 0), glm::vec4(249.0F/255.0F, 231.0F/255.0F, 42.0F/255.0F, 1.0F)), phase(0.25) {}

    void Update(float elapsedTime, InputState input) override {
      glm::mat4 rotation = glm::rotate(glm::mat4(1.0F), glm::radians(phase), glm::vec3(0, 0, 1));
      glm::vec4 rotatedDirection = rotation * glm::vec4(direction, 1.0);
      direction = glm::vec3(rotatedDirection.x, rotatedDirection.y, rotatedDirection.z);
    }

};