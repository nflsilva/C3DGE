#include <iostream>
#include <fstream>
#include <stdio.h>

#include "tools/Log.hpp"
#include "render/ShaderProgram.hpp"

ShaderProgram::ShaderProgram() {
  program = glCreateProgram();
  if(!program){
    Log::E("Program creation failed.");
    exit(1);
  }
}

ShaderProgram::~ShaderProgram(){

}

std::string ShaderProgram::LoadSourceFromFile(std::string fileName){
	std::ifstream file;
	file.open("resources/shaders/" + fileName, std::ios::in);
	if(!file)
	{
		Log::E("Error opening shader file " + fileName);
	  return NULL;
	}
  std::string content(
    (std::istreambuf_iterator<char>(file)),
    (std::istreambuf_iterator<char>()));
	file.close();
  return content;
}

void ShaderProgram::AddShader(std::string fileName, int type){
  int shader = glCreateShader(type);
  if(!shader){
    Log::E("Shader creation failed.");
    exit(1);
  }

  std::string code = LoadSourceFromFile(fileName);

  char *cstr = new char[code.length() + 1];
  strcpy(cstr, code.c_str());

  glShaderSource(shader, 1, &cstr, NULL);
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
  glAttachShader(program, shader);
  delete [] cstr;
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

  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    GLchar message[1024];
    glGetProgramInfoLog(program, 1024, &log_length, message);
    Log::E(message);
  }

  glValidateProgram(program);
  glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    GLchar message[1024];
    glGetProgramInfoLog(program, 1024, &log_length, message);
    Log::E(message);
  }
}

void ShaderProgram::Bind(){
  glUseProgram(program);
}