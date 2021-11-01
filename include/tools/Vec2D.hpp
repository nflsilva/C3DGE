#ifndef VEC2D_H
#define VEC2D_H

#include <string>

template <class T> class Vec2D
{
  public:
    T x, y;

    Vec2D(){}
    Vec2D(T x, T y) : x(x), y(y){}

    Vec2D operator * (T v){ return Vec2D(x * v, y * v); }
    Vec2D operator / (T v){ return Vec2D(x / v, y / v); }

    Vec2D operator + (Vec2D v){ return Vec2D(x + v.x, y + v.y); }
    Vec2D operator * (Vec2D v){ return Vec2D(x * v.x, y * v.y); }
    
    bool operator == (Vec2D v){ return x == v.x && y == v.y; }
    bool operator != (Vec2D v){ return x != v.x || y != v.y; }

    std::string ToString(){ return std::to_string(x) + ":" + std::to_string(y); };

};

typedef Vec2D<int> Vec2Di_t;
typedef Vec2D<double> Vec2Dd_t;

#endif