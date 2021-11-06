#include "render/Mesh.hpp"


Mesh::Mesh(
  std::vector<float> positions,
  std::vector<float> textureCoordinates, 
  std::vector<float> colors,
  std::vector<float> normals, 
  std::vector<int> indices){

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  vbos = new GLuint[4];
  glGenBuffers(4, vbos);
  glGenBuffers(1, &ebo);

  // positions
  glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * positions.size(), positions.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
  glEnableVertexAttribArray(0);

  // texture
  glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * textureCoordinates.size(), textureCoordinates.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
  glEnableVertexAttribArray(1);

  // colors
  glBindBuffer(GL_ARRAY_BUFFER, vbos[2]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * colors.size(), colors.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
  glEnableVertexAttribArray(2);

  // normals
  glBindBuffer(GL_ARRAY_BUFFER, vbos[3]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normals.size(), normals.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
  glEnableVertexAttribArray(3);

  // indices
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);

  this->size = indices.size();
}

Mesh::~Mesh(){
  GLuint arrays[] = { vao };
  glDeleteVertexArrays(1, arrays);
  glDeleteBuffers(4, vbos);
  delete(vbos);
}

void Mesh::Draw(){
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
}


