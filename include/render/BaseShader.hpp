#ifndef BASE_SHADER_HPP
#define BASE_SHADER_HPP

#include <list>
#include <string>
#include <string.h>
#include <map>
#include <GL/glew.h>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

class BaseShader {

  private:
    int id;
    std::list<int> shaders;
    std::map<std::string, int> uniforms;

    void AddShader(std::string fileName, int type);
    void Link();

  public:
    BaseShader(std::string vertexProgram, std::string fragmentProgram);
    ~BaseShader();
    void Bind();

    void AddUniform(std::string name);
    void SetUniformi(std::string name, int value);
    void SetUniformf(std::string name, float value);
    void SetUniformVector3f(std::string name, glm::vec3 value);
    void SetUniformMatrix4f(std::string name, glm::mat4 value);
};

#endif