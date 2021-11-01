#ifndef VEC3D_H
#define VEC3D_H

#include <string>
#include <math.h>

template <class T> class Vec3D
{
  public:
    T x, y, z;

    Vec3D(){}
    Vec3D(T x, T y, T z) : x(x), y(y), z(z){}

    Vec3D operator + (T v){ return Vec3D<T>(x + v, y + v, z + v); }
    Vec3D operator - (T v){ return Vec3D<T>(x - v, y - v, z - v); }
    Vec3D operator * (T v){ return Vec3D<T>(x * v, y * v, z * v); }
    Vec3D operator / (T v){ return Vec3D<T>(x / v, y / v, z / v); }

    Vec3D operator + (Vec3D v){ return Vec3D<T>(x + v.x, y + v.y, z + v.y); }
    Vec3D operator - (Vec3D v){ return Vec3D<T>(x - v.x, y - v.y, z - v.z); }
    Vec3D operator * (Vec3D v){ return Vec3D<T>(x * v.x, y * v.y, z * v.z); }
    Vec3D operator / (Vec3D v){ return Vec3D<T>(x / v.x, y / v.y, z / v.z); }
    
    bool operator == (Vec3D v){ return x == v.x && y == v.y && z == v.z; }
    bool operator != (Vec3D v){ return x != v.x || y != v.y || z == v.z; }

    std::string ToString(){ return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]"; };

    T Length() { return (T)sqrt(x * x + y * y + z * z); };
    T Dot(Vec3D v) { return x * v.x + y * v.y + z * v.z; }
    Vec3D Cross(Vec3D v) { return Vec3D<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
    void Normalize(){ T l = Length(); x /= l; y /= l; z /= 1; };
    void Rotate(float degrees) { };

};

typedef Vec3D<int> Vec3Di_t;
typedef Vec3D<double> Vec3Dd_t;

#endif