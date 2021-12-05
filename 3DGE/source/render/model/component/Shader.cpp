#include "tools/Utils.hpp"
#include "tools/ResourceLoader.hpp"
#include "tools/Log.hpp"
#include "render/model/component/Shader.hpp"

Shader::Shader(std::string* vertexProgram, std::string* fragmentProgram) {
  programId = glCreateProgram();
  if(!programId){
    Log::E("Program creation failed.");
    exit(1);
  }
  AddShader(vertexProgram, GL_VERTEX_SHADER);
  AddShader(fragmentProgram, GL_FRAGMENT_SHADER);
  Link();
  AddUniform("in_modelMatrix");
  AddUniform("in_viewMatrix");
  AddUniform("in_projectionMatrix");

  AddUniform("in_lightDirection");
  AddUniform("in_lightColor");
}

Shader::~Shader(){
  Unbind();
  for(int shader : shaders){
    glDetachShader(programId, shader);
    glDeleteShader(shader);
  }
  glDeleteProgram(programId);
}

void Shader::Bind(){
  glUseProgram(programId);
}

void Shader::Unbind(){
  glUseProgram(0);
}

void Shader::AddShader(std::string* code, int type){
  int shader = glCreateShader(type);
  if(!shader){
    Log::E("Shader creation failed.");
    exit(1);
  }

  char* source = Utils::StringToCharArray(*code);

  glShaderSource(shader, 1, &source, NULL);
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
  glAttachShader(programId, shader);

  delete [] code;
  shaders.push_front(shader);
}

void Shader::Link(){
  GLint success;

  glLinkProgram(programId);
  glGetProgramiv(programId, GL_LINK_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    GLchar message[1024];
    glGetProgramInfoLog(programId, 1024, &log_length, message);
    Log::E(message);
  }

  glValidateProgram(programId);
  glGetProgramiv(programId, GL_VALIDATE_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    GLchar message[1024];
    glGetProgramInfoLog(programId, 1024, &log_length, message);
    Log::E(message);
  }
}

void Shader::BindAttribute(int attribute, std::string variableName){
  glBindAttribLocation(programId, attribute, variableName.c_str());
}

void Shader::AddUniform(std::string name){
  int location = glGetUniformLocation(programId, name.c_str());
  if(location == GL_INVALID_VALUE || location == GL_INVALID_OPERATION || location == GL_INVALID_OPERATION){
    Log::E("Failed to create \"" + name + "\" uniform. Error: " + std::to_string(location));
    return;
  }
  uniforms[name] = location;
}
void Shader::SetUniformi(std::string name, int value){
	glUniform1i(uniforms[name], value);
}
void Shader::SetUniformf(std::string name, float value){
	glUniform1f(uniforms[name], value);
}
void Shader::SetUniformVector3f(std::string name, glm::vec3 value){
	glUniform3f(uniforms[name], value.x, value.y, value.z);
}
void Shader::SetUniformVector4f(std::string name, glm::vec4 value){
	glUniform4f(uniforms[name], value.x, value.y, value.z, value.a);
}
void Shader::SetUniformMatrix4f(std::string name, glm::mat4 value){
	glUniformMatrix4fv(uniforms[name], 1, GL_FALSE, &(value[0][0]));
}

void Shader::SetModelMatrix(glm::mat4 matrix){
  SetUniformMatrix4f("in_modelMatrix", matrix);
}
void Shader::SetViewMatrix(glm::mat4 matrix){
  SetUniformMatrix4f("in_viewMatrix", matrix);
}
void Shader::SetProjectionMatrix(glm::mat4 matrix){
  SetUniformMatrix4f("in_projectionMatrix", matrix);
}
void Shader::SetLightDirection(glm::vec3 direction){
  SetUniformVector3f("in_lightDirection", direction);
}
void Shader::SetLightColor(glm::vec4 color){
  SetUniformVector4f("in_lightColor", color);
}
