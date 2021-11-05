#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex {
  public:
    float x;
    float y; 
    float z;
    float tx;
    float ty;
    Vertex(): x(0), y(0), z(0), tx(0), ty(0) {}
    Vertex(float x, float y, float z, float tx, float ty) : x(x), y(y), z(z){}
};

#endif