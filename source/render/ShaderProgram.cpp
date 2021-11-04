#include "tools/Utils.hpp"
#include "tools/Resources.hpp"
#include "tools/Log.hpp"
#include "render/ShaderProgram.hpp"

ShaderProgram::ShaderProgram() {
  id = glCreateProgram();
  if(!id){
    Log::E("Program creation failed.");
    exit(1);
  }
}

ShaderProgram::~ShaderProgram(){
  for(int shader : shaders){
    glDetachShader(id, shader);
    glDeleteShader(shader);
  }
  glDeleteProgram(id);
}

int ShaderProgram::GetProgram(){
  return id;
}

void ShaderProgram::Bind(){
  glUseProgram(id);
}

void ShaderProgram::AddShader(std::string fileName, int type){
  int shader = glCreateShader(type);
  if(!shader){
    Log::E("Shader creation failed.");
    exit(1);
  }

  char* code = Utils::StringToCharArray(Resources::LoadShaderSource(fileName));

  glShaderSource(shader, 1, &code, NULL);
  glCompileShader(shader);

  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (success != GL_TRUE)
  {
      GLsizei log_length = 0;
      GLchar message[1024];
      glGetShaderInfoLog(shader, 1024, &log_length, message);
      Log::E(message);
  }
  glAttachShader(id, shader);

  delete [] code;
  shaders.push_front(shader);
}

void ShaderProgram::AddVertexShader(std::string fileName){
  AddShader(fileName, GL_VERTEX_SHADER);
  Link();
}

void ShaderProgram::AddGeometryShader(std::string fileName){
  AddShader(fileName, GL_GEOMETRY_SHADER);
  Link();
}

void ShaderProgram::AddFragmentShader(std::string fileName){
  AddShader(fileName, GL_FRAGMENT_SHADER);
  Link();
}

void ShaderProgram::Link(){
  GLint success;

  glLinkProgram(id);
  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    GLchar message[1024];
    glGetProgramInfoLog(id, 1024, &log_length, message);
    Log::E(message);
  }

  glValidateProgram(id);
  glGetProgramiv(id, GL_VALIDATE_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    GLchar message[1024];
    glGetProgramInfoLog(id, 1024, &log_length, message);
    Log::E(message);
  }
}

void ShaderProgram::AddUniform(std::string name){
  int location = glGetUniformLocation(id, name.c_str());
  if(location == GL_INVALID_VALUE || location == GL_INVALID_OPERATION || location == GL_INVALID_OPERATION){
    Log::E("Failed to create \"" + name + "\" uniform. Error: " + std::to_string(location));
    return;
  }
  uniforms[name] = location;
}

void ShaderProgram::SetUniformi(std::string name, int value){
	glUniform1i(uniforms[name], value);
}

void ShaderProgram::SetUniformf(std::string name, float value){
	glUniform1f(uniforms[name], value);
}

void ShaderProgram::SetUniformVector3f(std::string name, glm::vec3 value){
	glUniform3f(uniforms[name], value.x, value.y, value.z);
}

void ShaderProgram::SetUniformMatrix4f(std::string name, glm::mat4 value){
	glUniformMatrix4fv(uniforms[name], 1, GL_FALSE, &(value[0][0]));
}
