#include "render/Mesh.hpp"


Mesh::Mesh(std::vector<Vertex> vertices, std::vector<int> indices){

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);

  // position  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0 * sizeof(float)));
  glEnableVertexAttribArray(0);
  
  // texture
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  this->size = indices.size();
}

Mesh::~Mesh(){
  GLuint buffers[] = { vbo, ebo};
  GLuint arrays[] = { vao };
  glDeleteVertexArrays(1, arrays);
  glDeleteBuffers(2, buffers);
}

void Mesh::Draw(){
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
}


