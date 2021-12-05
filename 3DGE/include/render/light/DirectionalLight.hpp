#ifndef DIRECTIONAL_LIGHT_HPP
#define DIRECTIONAL_LIGHT_HPP

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include "ui/InputState.hpp"

class DirectionalLight {
  protected:
    glm::vec3 direction;
    glm::vec4 color;

  public:
    DirectionalLight(glm::vec3 direction, glm::vec4 color);
    virtual ~DirectionalLight();
    glm::vec3 GetDirection();
    glm::vec4 GetColor();

    virtual void Update(float elapsedTime, InputState input);
};

#endif