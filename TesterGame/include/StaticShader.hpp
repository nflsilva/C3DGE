#pragma once

#include "render/model/component/Shader.hpp"

#include "App.hpp"

class StaticShader : public Shader {
  private:

  public:
    StaticShader() : Shader(
      new std::string(BASE_DIR + "resource/shader/static/Vertex.glsl"), 
      new std::string(BASE_DIR + "resource/shader/static/Fragment.glsl")) {
    }

    void BindAttributes() {
      BindAttribute(0, "in_position");
      BindAttribute(1, "in_texCoord");
      BindAttribute(2, "in_normal");
    }

    void CreateUniformVariables() {
      
    }

};