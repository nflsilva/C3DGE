#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <string>

#include "tools/ResourceLoader.hpp"

class ResourceManager {
  private:
    static ResourceManager* instance;
    std::map<std::string, ResourceLoader::TextureData*> textures;
    std::map<std::string, ResourceLoader::MeshData*> meches;
    std::map<std::string, std::string*> shaders;
    ResourceManager();
    ~ResourceManager();

  public:
    ResourceManager* GetInstance();
    void CleanUp();
    ResourceLoader::TextureData* GetTextureData(std::string fileName);
    ResourceLoader::MeshData* GetMeshData(std::string fileName);
    std::string* GetShaderData(std::string fileName);
};

#endif