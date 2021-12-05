#include "core/ResourceManager.hpp"

ResourceManager* ResourceManager::instance = NULL;

ResourceManager* ResourceManager::GetInstance(){
  if(!instance)
    instance = new ResourceManager();
  return instance;
}

ResourceManager::ResourceManager(){}

ResourceManager::~ResourceManager(){}

void ResourceManager::CleanUp(){
  for(auto i = textures.begin(); i != textures.end(); ++i) delete(i->second);
  for(auto i = meches.begin(); i != meches.end(); ++i) delete(i->second);
  for(auto i = shaders.begin(); i != shaders.end(); ++i) delete(i->second);
}

ResourceLoader::TextureData* ResourceManager::GetTextureData(std::string fileName){
  ResourceLoader::TextureData* data = NULL;
  if(textures.count(fileName) == 0){
    data = ResourceLoader::LoadTextureData(fileName);
    textures[fileName] = data;
  }
  return data;
}

ResourceLoader::MeshData* ResourceManager::GetMeshData(std::string fileName){
  ResourceLoader::MeshData* data = NULL;
  if(meches.count(fileName) == 0){
    data = ResourceLoader::LoadMeshDataIndexed(fileName);
    meches[fileName] = data;
  }
  return data;
}

std::string* ResourceManager::GetShaderData(std::string fileName){
  std::string* data = NULL;
  if(shaders.count(fileName) == 0){
    data = ResourceLoader::LoadShaderSource(fileName);
    shaders[fileName] = data;
  }
  return data;
}