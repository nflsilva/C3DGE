#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include "tools/Log.hpp"
#include "tools/ResourceLoader.hpp"

class Texture {
  private:
    GLuint id;
    int width, height, bpp;

  public:
    Texture(std::string* file);
    ~Texture();

    int GetId();
    void Bind(unsigned int slot);
    void Unbind();

};

#endif