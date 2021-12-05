#ifndef SHADER_HPP
#define SHADER_HPP

#include <list>
#include <string>
#include <string.h>
#include <map>
#include <GL/glew.h>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

class Shader {

  private:
    int programId;
    std::list<int> shaders;
    std::map<std::string, int> uniforms;

    void AddShader(std::string* code, int type);
    void Link();

  protected:
    void BindAttribute(int attribute, std::string variableName);
    void AddUniform(std::string name);

  public:
    Shader(std::string* vertexProgram, std::string* fragmentProgram);
    virtual ~Shader();
    void Bind();
    void Unbind();

    void SetUniformi(std::string name, int value);
    void SetUniformf(std::string name, float value);
    void SetUniformVector3f(std::string name, glm::vec3 value);
    void SetUniformVector4f(std::string name, glm::vec4 value);
    void SetUniformMatrix4f(std::string name, glm::mat4 value);

    void SetModelMatrix(glm::mat4 matrix);
    void SetViewMatrix(glm::mat4 matrix);
    void SetProjectionMatrix(glm::mat4 matrix);
    void SetLightDirection(glm::vec3 direction);
    void SetLightColor(glm::vec4 color);

    virtual void BindAttributes() = 0;
    virtual void CreateUniformVariables() = 0;
};

#endif