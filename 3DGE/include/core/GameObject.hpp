#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "render/model/BaseModel.hpp"
#include "ui/InputState.hpp"

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
    virtual ~GameObject();
    
    BaseModel* GetModel();
    glm::mat4 GetModelMatrix();

    void SetPosition(glm::vec3 newPosition);
    void Move(glm::vec3 delta);
    void Rotate(glm::vec3 delta);
    void Scale(glm::vec3 delta);

    virtual void Update(float elapsedTime, InputState input);
};

#endif