#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>
#include "render/Vertex.hpp"

class Mesh {
  private:
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    int size;

  public:
    Mesh(std::vector<Vertex> vertices, std::vector<int> indices);
    ~Mesh();
    void Draw();
};

#endif