#pragma once

#include "core/GameObject.hpp"

#include "StaticShader.hpp"

class Quad : public GameObject {
  private:
    glm::vec3 rotationSpeed;

  public:
    Quad(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : GameObject(NULL, position, rotation, scale), rotationSpeed(glm::vec3(0.0F)) {

			ResourceLoader::MeshData modelData;
			modelData.vertices = {
				-0.5f,  0.5f, 0.0f,
				-0.5f, -0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				 0.5f,  0.5f, 0.0f,
			};
			modelData.indices = {
				0, 1, 3,
				3, 1, 2
			};
			modelData.textureCoordinates = {
				0.0f, 0.0f,
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,
			};

			Mesh* modelMesh = new Mesh(&modelData);
			Texture* texture = new Texture(new std::string(BASE_DIR + "resource/texture/debug2.png"));
			Shader* staticShader = new StaticShader();
      model = new BaseModel(modelMesh, texture, staticShader);
    }

    void Update(float elapsedTime, InputState input) override {

      if(input.IsMousePressed(0)){
        //rotationSpeed.y += 5.0F;
      }
      else if(input.IsMousePressed(1)){
        //rotationSpeed.y -= 5.0F;
      }

      if(rotationSpeed.y != 0){
        Rotate(rotationSpeed);
        rotationSpeed.y = (int)rotationSpeed.y / 1.05f;
        UpdateModelMatrix();
      }
    
    }

};