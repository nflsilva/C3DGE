#ifndef ShaderProgram_PROGRAM_HPP
#define ShaderProgram_PROGRAM_HPP

#include <list>
#include <string>
#include <string.h>
#include <map>
#include <GL/glew.h>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

class ShaderProgram {

  private:
    int id;
    std::list<int> shaders;
    std::map<std::string, int> uniforms;

    void AddShader(std::string fileName, int type);
    void Link();

  public:
    ShaderProgram();
    ~ShaderProgram();
    int GetProgram();
    void Bind();

    void AddVertexShader(std::string fileName);
    void AddGeometryShader(std::string fileName);
    void AddFragmentShader(std::string fileName);

    void AddUniform(std::string name);
    void SetUniformi(std::string name, int value);
    void SetUniformf(std::string name, float value);
    void SetUniformVector3f(std::string name, glm::vec3 value);
    void SetUniformMatrix4f(std::string name, glm::mat4 value);

};

#endif