#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>
#include "render/Vertex.hpp"

class Mesh {
  private:
    GLuint vbo;
    GLuint ibo;
    int size;

  public:
    Mesh(std::vector<Vertex> vertices, std::vector<int> indices);
    ~Mesh();
    void Draw();
};

#endif