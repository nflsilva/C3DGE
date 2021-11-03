#ifndef MESH_HPP
#define MESH_HPP

#include <list>
#include <GL/glew.h>
#include "render/Vertex.hpp"

class Mesh {
  private:
    GLuint vbo;
    int size;

  public:
    Mesh(Vertex* vertices, int size);
    void Draw();
};

#endif