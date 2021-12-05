#pragma once

#include <iostream>
#include <glm/vec3.hpp>

#include "core/CoreEngine.hpp"
#include "core/CoreEngineDelegate.hpp"
#include "render/model/BaseModel.hpp"
#include "tools/Log.hpp"
#include "tools/ResourceLoader.hpp"

#include "object/Quad.hpp"
#include "object/Cube.hpp"
#include "object/TeddyBear.hpp"
#include "object/Tree.hpp"
#include "object/Mongus.hpp"
#include "StaticShader.hpp"
#include "MovingCamera.hpp"
#include "light/Sun.hpp"

class Game : public CoreEngineDelegate {
  private:
    CoreEngine* engine;

  public:
		Game(CoreEngine* engine) : engine(engine) {}
		~Game(){};

		void OnStart(){
			BaseCamera* camera = new MovingCamera(glm::vec3(0, 0, 2), glm::vec3(0,0,-1), glm::vec3(0,1,0));
			engine->SetCamera(camera);

			//engine->AddGameObject(new Quad(glm::vec3(5, 0, -5), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
			//engine->AddGameObject(new TeddyBear(glm::vec3(0, 0, -5), glm::vec3(0, 0, 0), glm::vec3(0.1, 0.1, 0.1)));
			//engine->AddGameObject(new Tree(glm::vec3(-5, 0, -5), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5)));

			ResourceLoader::MeshData* modelData = ResourceLoader::LoadMeshDataIndexed(BASE_DIR + "resource/mesh/amongus.obj");
			Mesh* mesh = new Mesh(modelData);
			Texture* texture = new Texture(new std::string(BASE_DIR + "resource/texture/amongus.jpg"));
			Shader* staticShader = new StaticShader();
			BaseModel* model = new BaseModel(mesh, texture, staticShader);

			for(int n = 0; n < 10; n++){

				float x = rand() % 10;
				float y = rand() % 10;
				float z = rand() % 10;
				engine->AddGameObject(new Mongus(glm::vec3(x, y, -z), glm::vec3(0, 0, 0), glm::vec3(0.025, 0.025, 0.025)));

			}



			engine->AddDirectionalLight(new Sun());

		/*
			int size = 20;
			float* vertexY = new float[size * size];
			for(int x = 0; x < size; x++) {
				for(int y = 0; y < size; y++){
					vertexY[x * size + y] = -1;
				}
			}
			glm::vec4 color(0.2, 0.2, 0.5, 0.5);
			Resources::MeshData terrainData;
			for(int z = 0; z < size - 1; z++){
				for(int x = 0; x < size; x++){

					//n
					if(vertexY[z * size + x] == -1) vertexY[z * size + x] = 1 - float(rand())/float((RAND_MAX)) * 2.0;
					terrainData.vertices.push_back(x);
					terrainData.vertices.push_back(vertexY[z * size + x]);
					terrainData.vertices.push_back(z);
					terrainData.colors.push_back(color.x);
					terrainData.colors.push_back(color.y);
					terrainData.colors.push_back(color.z);
					terrainData.colors.push_back(color.a);
					//n + w
					if(vertexY[(z + 1) * size + x] == -1) vertexY[(z + 1) * size + x] = 1 - float(rand())/float((RAND_MAX)) * 2.0;
					terrainData.vertices.push_back(x);
					terrainData.vertices.push_back(vertexY[(z + 1) * size + x]);
					terrainData.vertices.push_back(z + 1);
					terrainData.colors.push_back(color.x);
					terrainData.colors.push_back(color.y);
					terrainData.colors.push_back(color.z);
					terrainData.colors.push_back(color.a);
					//n + 1
					if(vertexY[z * size + x + 1] == -1) vertexY[z * size + x + 1] = 1 - float(rand())/float((RAND_MAX)) * 2.0;
					terrainData.vertices.push_back(x + 1);
					terrainData.vertices.push_back(vertexY[z * size + x + 1]);
					terrainData.vertices.push_back(z);
					terrainData.colors.push_back(color.x);
					terrainData.colors.push_back(color.y);
					terrainData.colors.push_back(color.z);
					terrainData.colors.push_back(color.a);

					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(1.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(1.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(1.0);
					terrainData.normals.push_back(0.0);

					//n + 1
					terrainData.vertices.push_back(x + 1);
					terrainData.vertices.push_back(vertexY[z * size + x + 1]);
					terrainData.vertices.push_back(z);
					terrainData.colors.push_back(color.x);
					terrainData.colors.push_back(color.y);
					terrainData.colors.push_back(color.z);
					terrainData.colors.push_back(color.a);
					//n + w
					terrainData.vertices.push_back(x);
					terrainData.vertices.push_back(vertexY[(z + 1) * size + x]);
					terrainData.vertices.push_back(z + 1);
					terrainData.colors.push_back(color.x);
					terrainData.colors.push_back(color.y);
					terrainData.colors.push_back(color.z);
					terrainData.colors.push_back(color.a);
					//n + 1 + w
					if(vertexY[(z + 1) * size + x + 1] == -1) vertexY[(z + 1) * size + x + 1] = 1 - float(rand())/float((RAND_MAX)) * 2.0;
					terrainData.vertices.push_back(x + 1);
					terrainData.vertices.push_back(vertexY[(z + 1) * size + x + 1]);
					terrainData.vertices.push_back(z + 1);
					terrainData.colors.push_back(color.x);
					terrainData.colors.push_back(color.y);
					terrainData.colors.push_back(color.z);
					terrainData.colors.push_back(color.a);

					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(1.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(1.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(0.0);
					terrainData.normals.push_back(1.0);
					terrainData.normals.push_back(0.0);

				}
			}
			delete(vertexY);
			*/
		
		}

		void OnUpdate(float elapsedTime, InputState input){

		}

		void OnRender(){

		}

		void OnDestroy(){
			
		}
};



