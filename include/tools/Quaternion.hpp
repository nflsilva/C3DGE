#ifndef QUATERNION_H
#define QUATERNION_H

#include <string>
#include <math.h>
#include "tools/Vec3D.hpp"

class Quaternion {

  public:
    float x, y, z, w;

    Quaternion(){}
    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}
    Quaternion(Vec3D axis, float angle){
      float sinHalfAngle = sin(angle / 2);
      float cosHalfAngle = cos(angle / 2);
      x = axis.x * sinHalfAngle;
      y = axis.y * sinHalfAngle;
      z = axis.z * sinHalfAngle;
      w = cosHalfAngle;
    }

    Quaternion operator * (float v){ return Quaternion(x * v, y * v, z * v, w * v); }

    Quaternion operator * (Vec3D v){ 
      return Quaternion(
        w * v.x + y * v.z - z * v.y, 
        w * v.y + z * v.x - x * v.z, 
        w * v.z + x * v.y - y * v.x, 
        -x * v.x - y * v.y - z * v.z); 
    }

    Quaternion operator + (Quaternion v){ return Quaternion(x + v.x, y + v.y, z + v.y, w + v.w); }
    Quaternion operator - (Quaternion v){ return Quaternion(x - v.x, y - v.y, z - v.z, w - v.w); }
    Quaternion operator * (Quaternion v){ return Quaternion(x * v.x, y * v.y, z * v.z, w * v.w); }
    
    bool operator == (Quaternion v){ return x == v.x && y == v.y && z == v.z; }
    bool operator != (Quaternion v){ return x != v.x || y != v.y || z == v.z; }

    std::string ToString(){ return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]"; };

    float Length() { return (float)sqrt(x * x + y * y + z * z + w * w); };
    Quaternion Conjugate() { return Quaternion(-x, -y, -z, w); };
    float Dot(Quaternion v) { return x * v.x + y * v.y + z * v.z + w * v.w; }
    void Normalize(){ float l = Length(); x /= l; y /= l; z /= l; w /= l; };

};

#endif