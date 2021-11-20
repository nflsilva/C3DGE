#include "tools/Utils.hpp"
#include "tools/Resources.hpp"
#include "tools/Log.hpp"
#include "render/BaseShader.hpp"

BaseShader::BaseShader(std::string vertexProgram, std::string fragmentProgram) {
  id = glCreateProgram();
  if(!id){
    Log::E("Program creation failed.");
    exit(1);
  }
  AddShader(vertexProgram, GL_VERTEX_SHADER);
  AddShader(fragmentProgram, GL_FRAGMENT_SHADER);
  Link();
}


BaseShader::~BaseShader(){
  for(int shader : shaders){
    glDetachShader(id, shader);
    glDeleteShader(shader);
  }
  glDeleteProgram(id);
}

void BaseShader::Bind(){
  glUseProgram(id);
}

void BaseShader::AddShader(std::string fileName, int type){
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

void BaseShader::Link(){
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

void BaseShader::AddUniform(std::string name){
  int location = glGetUniformLocation(id, name.c_str());
  if(location == GL_INVALID_VALUE || location == GL_INVALID_OPERATION || location == GL_INVALID_OPERATION){
    Log::E("Failed to create \"" + name + "\" uniform. Error: " + std::to_string(location));
    return;
  }
  uniforms[name] = location;
}

void BaseShader::SetUniformi(std::string name, int value){
	glUniform1i(uniforms[name], value);
}

void BaseShader::SetUniformf(std::string name, float value){
	glUniform1f(uniforms[name], value);
}

void BaseShader::SetUniformVector3f(std::string name, glm::vec3 value){
	glUniform3f(uniforms[name], value.x, value.y, value.z);
}

void BaseShader::SetUniformMatrix4f(std::string name, glm::mat4 value){
	glUniformMatrix4fv(uniforms[name], 1, GL_FALSE, &(value[0][0]));
}
