#pragma once

#include "core/GameObject.hpp"

#include "StaticShader.hpp"

class Cube : public GameObject {
  private:
    glm::vec3 rotationSpeed;

  public:
    Cube(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : GameObject(NULL, position, rotation, scale), rotationSpeed(glm::vec3(0.0F)) {

			ResourceLoader::MeshData modelData;
			modelData.vertices = {
				-0.5f,  0.5f, 0.5f,		//0
				-0.5f, -0.5f, 0.5f,		//1
				 0.5f, -0.5f, 0.5f,		//2
				 0.5f,  0.5f, 0.5f,		//3

				 0.5f,  0.5f, 0.5f,		//4
				 0.5f, -0.5f, 0.5f,		//5
				 0.5f, -0.5f, -0.5f,	//6
				 0.5f,  0.5f, -0.5f,	//7

				 0.5f,  0.5f, -0.5f,	//8
         0.5f, -0.5f, -0.5f,	//9
        -0.5f, -0.5f, -0.5f,	//10
        -0.5f,  0.5f, -0.5f,	//11

        -0.5f,  0.5f, -0.5f,	//12
        -0.5f, -0.5f, -0.5f,	//13
				-0.5f, -0.5f,  0.5f,	//14
				-0.5f,  0.5f,  0.5f,	//15

        -0.5f,  0.5f, 0.5f,		//16
         0.5f,  0.5f, 0.5f,		//17
         0.5f,  0.5f, -0.5f,	//18
        -0.5f,  0.5f, -0.5f,	//19

				-0.5f, -0.5f, 0.5f,		//20
				 0.5f, -0.5f, 0.5f,		//21
         0.5f, -0.5f, -0.5f,	//22
        -0.5f, -0.5f, -0.5f,	//23


			};
			modelData.indices = {
				0, 1, 3,
				3, 1, 2,

				4, 5, 7,
				7, 5, 6,

        8, 9, 11,
				11, 9, 10,

        12, 13, 15,
				15, 13, 14,

        16, 17, 19,
				19, 17, 18,

        20, 21, 23,
				23, 21, 22,

			};
			modelData.textureCoordinates = {
				0.0f, 0.0f,
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,

				0.0f, 0.0f,	
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,

        0.0f, 0.0f,	
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,

        0.0f, 0.0f,	
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,

        0.0f, 0.0f,	
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,

        0.0f, 0.0f,	
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,

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

      if(input.IsKeyPressed(InputState::KEY_1)){
        rotationSpeed.y += 2.5F;
      }
      else if(input.IsKeyPressed(InputState::KEY_2)){
        rotationSpeed.y -= 2.5F;
      }

      if(rotationSpeed.y != 0){
        Rotate(rotationSpeed);
        rotationSpeed.y = (int)rotationSpeed.y / 1.05f;
        UpdateModelMatrix();
      }
    
    }

};