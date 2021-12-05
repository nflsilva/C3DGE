#include "render/light/DirectionalLight.hpp"

DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec4 color) : direction(direction), color(color) {

}
DirectionalLight::~DirectionalLight(){}

glm::vec3 DirectionalLight::GetDirection(){
  return direction;
}
glm::vec4 DirectionalLight::GetColor(){
  return color;
}
void DirectionalLight::Update(float elapsedTime, InputState input){
  //does nothing
}