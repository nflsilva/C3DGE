#ifndef ShaderProgram_PROGRAM_HPP
#define ShaderProgram_PROGRAM_HPP

#include <string>
#include <string.h>
#include <GL/glew.h>

class ShaderProgram {

  private:
    int program;
    std::string LoadSourceFromFile(std::string fileName);
    void AddShader(std::string fileName, int type);
    void Link();

  public:
    ShaderProgram();
    ~ShaderProgram();
    void AddVertexShader(std::string fileName);
    void AddGeometryShader(std::string fileName);
    void AddFragmentShader(std::string fileName);
    void Bind();
};

#endif