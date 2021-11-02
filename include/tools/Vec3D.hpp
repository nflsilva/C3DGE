#ifndef VEC3D_H
#define VEC3D_H

#include <string>
#include <math.h>

class Vec3D {
  public:
    float x, y, z;

    Vec3D(){}
    Vec3D(float x, float y, float z) : x(x), y(y), z(z){}

    Vec3D operator + (float v){ return Vec3D(x + v, y + v, z + v); }
    Vec3D operator - (float v){ return Vec3D(x - v, y - v, z - v); }
    Vec3D operator * (float v){ return Vec3D(x * v, y * v, z * v); }
    Vec3D operator / (float v){ return Vec3D(x / v, y / v, z / v); }

    Vec3D operator + (Vec3D v){ return Vec3D(x + v.x, y + v.y, z + v.y); }
    Vec3D operator - (Vec3D v){ return Vec3D(x - v.x, y - v.y, z - v.z); }
    Vec3D operator * (Vec3D v){ return Vec3D(x * v.x, y * v.y, z * v.z); }
    Vec3D operator / (Vec3D v){ return Vec3D(x / v.x, y / v.y, z / v.z); }
    
    bool operator == (Vec3D v){ return x == v.x && y == v.y && z == v.z; }
    bool operator != (Vec3D v){ return x != v.x || y != v.y || z == v.z; }

    std::string ToString(){ return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]"; };

    float Length() { return (float)sqrt(x * x + y * y + z * z); };
    float Dot(Vec3D v) { return x * v.x + y * v.y + z * v.z; }
    Vec3D Cross(Vec3D v) { return Vec3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
    void Normalize(){ float l = Length(); x /= l; y /= l; z /= 1; };
    void Rotate(float degrees) { };

};

#endif