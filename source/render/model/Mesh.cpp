#include "render/model/Mesh.hpp"
#include <cstdlib>
#include <ctime>

Mesh::Mesh(
  std::vector<float> positions,
  std::vector<float> textureCoordinates, 
  std::vector<float> colors,
  std::vector<float> normals, 
  std::vector<int> indices){

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  LoadIntoIndexBuffer(indices);
  LoadIntoAttributeList(0, 3, positions);
  LoadIntoAttributeList(1, 2, textureCoordinates);

  Unbind();
}

Mesh::Mesh(Resources::MeshData* data) : Mesh(data->vertices, data->textureCoordinates, data->colors, data->normals, data->indices) {}

Mesh::~Mesh(){
  Unbind();
  GLuint arrays[] = { vao };
  glDeleteVertexArrays(1, arrays);
  glDeleteBuffers(vbos.size(), vbos.data());
}

void Mesh::LoadIntoAttributeList(int location, int length, std::vector<float> data){
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(location, length, GL_FLOAT, GL_FALSE, 0, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  vbos.push_back(vbo);
}

void Mesh::LoadIntoIndexBuffer(std::vector<int> indices) {
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);
  this->size = indices.size();
  vbos.push_back(vbo);
}

void Mesh::Unbind(){
  glBindVertexArray(0);
}

void Mesh::Render(){
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}


