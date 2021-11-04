#include "render/Mesh.hpp"


Mesh::Mesh(std::vector<Vertex> vertices, std::vector<int> indices){
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ibo);
  this->size = indices.size();

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);
}

void Mesh::Draw(){
  
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
}


