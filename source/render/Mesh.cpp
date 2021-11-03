#include "render/Mesh.hpp"


Mesh::Mesh(Vertex* vertices, int size){
  glGenBuffers(1, &vbo);
  this->size = size;

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, size * sizeof(Vertex), vertices, GL_STATIC_DRAW);
}

void Mesh::Draw(){

  int attribArray = 0;
  glEnableVertexAttribArray(attribArray);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(attribArray, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

  glDrawArrays(GL_TRIANGLES, 0, size);

  glDisableVertexAttribArray(attribArray);
}


