#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex {
  public:
    float x, y, z;
    Vertex(): x(0), y(0), z(0) {}
    Vertex(float x, float y, float z) : x(x), y(y), z(z){}
};

#endif