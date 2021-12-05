#ifndef BASE_MODEL_HPP
#define BASE_MODEL_HPP

#include "render/model/component/Shader.hpp"
#include "render/model/component/Mesh.hpp"
#include "render/model/component/Texture.hpp"

class BaseModel {
  protected:
    Mesh* mesh;
    Texture* texture;
    Shader* shader;
  public:
    BaseModel(Mesh* mesh, Texture* texture, Shader* shader);
    ~BaseModel();
    Mesh* GetMesh();
    Texture* GetTexture();
    Shader* GetShader();
};

#endif