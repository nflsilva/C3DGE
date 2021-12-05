#pragma once

#include "core/GameObject.hpp"

#include "StaticShader.hpp"

class TeddyBear : public GameObject {
  private:
    glm::vec3 rotationSpeed;

  public:
    TeddyBear(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : GameObject(NULL, position, rotation, scale), rotationSpeed(glm::vec3(0.0F)) {

			ResourceLoader::MeshData* modelData = ResourceLoader::LoadMeshDataIndexed(BASE_DIR + "resource/mesh/teddyBear.obj");
			Mesh* modelMesh = new Mesh(modelData);
			Texture* texture = new Texture(new std::string(BASE_DIR + "resource/texture/debug2.png"));
			Shader* staticShader = new StaticShader();
      model = new BaseModel(modelMesh, texture, staticShader);
      rotationSpeed.y = 1.0F;
    }

    void Update(float elapsedTime, InputState input) override {

      if(rotationSpeed.y != 0){
        Rotate(rotationSpeed);
        UpdateModelMatrix();
      }
    
    }

};