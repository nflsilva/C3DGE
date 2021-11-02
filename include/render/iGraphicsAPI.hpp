#ifndef IGRAPHICS_API_HPP
#define IGRAPHICS_API_HPP

#include <GL/glew.h>

class iGraphicsAPI {
  public:
    virtual void Init() = 0;
    virtual void ClearScreen() = 0;
};

#endif