#pragma once

#include "core/GameObject.hpp"
#include "tools/Log.hpp"
#include "StaticShader.hpp"

class Mongus : public GameObject {
  private:
		glm::vec3 rotationSpeed;

  public:
    Mongus(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : GameObject(NULL, position, rotation, scale), rotationSpeed(glm::vec3(0.0F)) {
			ResourceLoader::MeshData* modelData = ResourceLoader::LoadMeshDataIndexed(BASE_DIR + "resource/mesh/amongus.obj");
			Mesh* modelMesh = new Mesh(modelData);
			Texture* texture = new Texture(new std::string(BASE_DIR + "resource/texture/amongus.jpg"));
			Shader* staticShader = new StaticShader();
      model = new BaseModel(modelMesh, texture, staticShader);
    }

    void Update(float elapsedTime, InputState input) override {

			if(input.IsMousePressed(0)){
				float angle = input.GetDragDeltaX();
				Rotate(glm::vec3(0, glm::radians(-angle), 0));
				UpdateModelMatrix();
			}
    }

};