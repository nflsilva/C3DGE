#include "render/Mesh.hpp"


Mesh::Mesh(
  std::vector<float> positions,
  std::vector<float> textureCoordinates, 
  std::vector<float> colors,
  std::vector<float> normals, 
  std::vector<int> indices){

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  if(positions.size() > 0)
    vbos.push_back(LoadIntoVBO(0, 3, positions));

  if(colors.size() > 0)
    vbos.push_back(LoadIntoVBO(1, 4, colors));

  if(normals.size() > 0)
    vbos.push_back(LoadIntoVBO(2, 3, normals));

  if(textureCoordinates.size() > 0)
    vbos.push_back(LoadIntoVBO(3, 2, textureCoordinates));

  // indices
  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);

  this->size = indices.size();
}

Mesh::~Mesh(){
  GLuint arrays[] = { vao };
  glDeleteVertexArrays(1, arrays);
  glDeleteBuffers(vbos.size(), vbos.data());
}

GLuint Mesh::LoadIntoVBO(int location, int length, std::vector<float> data){
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (int)data.size(), data.data(), GL_STATIC_DRAW);
  glEnableVertexAttribArray(location);
  glVertexAttribPointer(location, length, GL_FLOAT, GL_FALSE, length * sizeof(float), 0);
  return vbo;
}

void Mesh::Draw(){
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
}


