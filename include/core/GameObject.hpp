#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp>

#include "render/model/BaseModel.hpp"

class GameObject {
  protected:
    BaseModel* model;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 modelMatrix;

    void UpdateModelMatrix();

  public:
    GameObject(BaseModel* model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    ~GameObject();
    
    BaseModel* GetModel();
    glm::mat4 GetModelMatrix();

};

#endif