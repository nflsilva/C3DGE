#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>

#include "tools/Resources.hpp"

class Mesh {
  private:
    GLuint vao;
    std::vector<GLuint> vbos;
    int size;

    void LoadIntoAttributeList(int location, int size, std::vector<float> data);
    void LoadIntoIndexBuffer(std::vector<int> data);
    void Unbind();

  public:
    Mesh(std::vector<float> positions,
          std::vector<float> textureCoordinates, 
          std::vector<float> colors,
          std::vector<float> normals, 
          std::vector<int> indices);
    Mesh(Resources::MeshData* data);
    ~Mesh();
    void Render();
};

#endif