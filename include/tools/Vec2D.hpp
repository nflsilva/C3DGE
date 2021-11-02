#ifndef VEC2D_H
#define VEC2D_H

#include <string>
#include <math.h>

class Vec2D {
  
  public:
    float x, y;

    Vec2D(){}
    Vec2D(float x, float y) : x(x), y(y){}

    Vec2D operator + (float v){ return Vec2D(x + v, y + v); }
    Vec2D operator - (float v){ return Vec2D(x - v, y - v); }
    Vec2D operator * (float v){ return Vec2D(x * v, y * v); }
    Vec2D operator / (float v){ return Vec2D(x / v, y / v); }

    Vec2D operator + (Vec2D v){ return Vec2D(x + v.x, y + v.y); }
    Vec2D operator - (Vec2D v){ return Vec2D(x - v.x, y - v.y); }
    Vec2D operator * (Vec2D v){ return Vec2D(x * v.x, y * v.y); }
    Vec2D operator / (Vec2D v){ return Vec2D(x / v.x, y / v.y); }
    
    bool operator == (Vec2D v){ return x == v.x && y == v.y; }
    bool operator != (Vec2D v){ return x != v.x || y != v.y; }

    std::string ToString(){ return "[" + std::to_string(x) + ", " + std::to_string(y) + "]"; };

    float Length() { return (float)sqrt(x * x + y * y); };
    float Dot(Vec2D v) { return x * v.x + y * v.y; }
    void Normalize(){ float l = Length(); x /= l; y/= l; };
    Vec2D Rotate(float degrees) { double rad = degrees * M_PI / 180; double c = cos(rad); double s = sin(rad); return Vec2D((float)(x*c-y*s), (float)(x*s+y*c));};

};

#endif