#pragma once

#include "core/GameObject.hpp"

#include "StaticShader.hpp"

class Tree : public GameObject {
  private:
    glm::vec3 rotationSpeed;

  public:
    Tree(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : GameObject(NULL, position, rotation, scale), rotationSpeed(glm::vec3(0.0F)) {

			ResourceLoader::MeshData* modelData = ResourceLoader::LoadMeshDataIndexed(BASE_DIR + "resource/mesh/tree.obj");

			Mesh* modelMesh = new Mesh(modelData);
			Texture* texture = new Texture(new std::string(BASE_DIR + "resource/texture/debug2.png"));
			Shader* staticShader = new StaticShader();
      model = new BaseModel(modelMesh, texture, staticShader);
    }

    void Update(float elapsedTime, InputState input) override {

      if(input.IsKeyPressed(InputState::KEY_1)){ //1
        rotationSpeed.y += 2.5F;
      }
      else if(input.IsKeyPressed(InputState::KEY_2)){ //2
        rotationSpeed.y -= 2.5F;
      }

      if(rotationSpeed.y != 0){
        Rotate(rotationSpeed);
        rotationSpeed.y = (int)rotationSpeed.y / 1.05f;
        UpdateModelMatrix();
      }
    
    }

};