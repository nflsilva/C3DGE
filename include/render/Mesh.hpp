#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>
#include "render/Vec4DTO.hpp"

class Mesh {
  private:
    GLuint vao;
    std::vector<GLuint> vbos;
    GLuint ebo;
    int size;

    GLuint LoadIntoVBO(int location, int size, std::vector<float> data);

  public:
    Mesh(std::vector<float> positions,
          std::vector<float> textureCoordinates, 
          std::vector<float> colors,
          std::vector<float> normals, 
          std::vector<int> indices);
    ~Mesh();
    void Draw();
};

#endif