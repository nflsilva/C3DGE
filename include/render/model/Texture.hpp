#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include "tools/Log.hpp"

class Texture {
  private:
    GLuint id;
    int width, height, bpp;

  public:
    Texture(std::string fileName);
    ~Texture();

    int GetId();
    void Bind(unsigned int slot);
    void Unbind();

};

#endif