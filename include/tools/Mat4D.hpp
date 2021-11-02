#ifndef MAT4D_H
#define MAT4D_H

#include <string>
#include <math.h>
#include "tools/Vec3D.hpp"

class Mat4D {

  private:
    float data[16] = { 0 };

  public:
    Mat4D(){}

    void SetValueAt(int row, int column, float value) { data[row * 4 + column] = value; };
    float GetValueAt(int row, int column) { return data[row * 4 + column]; };

    Mat4D operator * (Mat4D m){ 
      Mat4D r;
      for(int row = 0; row < 4; row++)
      {
        for(int col = 0; col < 4; col++)
        {
          r.SetValueAt(row, col, 
            this->GetValueAt(row, 0) * m.GetValueAt(0, col) + 
            this->GetValueAt(row, 1) * m.GetValueAt(1, col) +
            this->GetValueAt(row, 2) * m.GetValueAt(2, col) +
            this->GetValueAt(row, 3) * m.GetValueAt(3, col)
          );
        }
      }
      return r;
    }

    Vec3D operator * (Vec3D v){ 
      Vec3D r;
      r.x = GetValueAt(0, 0) * v.x + GetValueAt(0, 1) * v.y + GetValueAt(0, 2) * v.z;
      r.y = GetValueAt(1, 0) * v.x + GetValueAt(1, 1) * v.y + GetValueAt(1, 2) * v.z;
      r.z = GetValueAt(2, 0) * v.x + GetValueAt(2, 1) * v.y + GetValueAt(2, 2) * v.z;
      return r;
    }

    std::string ToString(){ 
      std::string r = "";
      for(int row = 0; row < 4; row++)
      {
        for(int col = 0; col < 4; col++)
        {
          r += std::to_string(GetValueAt(row, col)) + ", ";
        }
        r += "\n";
      }
      return r;
    }

    static Mat4D Identity(){ 
      Mat4D r ;
      for(int i = 0; i < 4; i++) {
        r.SetValueAt(i, i, 1);
      }
      return r;
    }

    static Mat4D Translation(float x, float y, float z){ 
      Mat4D r = Identity();
      r.SetValueAt(0, 3, x);
      r.SetValueAt(1, 3, y);
      r.SetValueAt(2, 3, z);
      return r;
    }
    
    static Mat4D Scale(float x, float y, float z){ 
      Mat4D r;
      r.SetValueAt(0, 0, x);
      r.SetValueAt(1, 1, y);
      r.SetValueAt(2, 2, z);
      return r;
    }

    static Mat4D Rotation(float x, float y, float z){ 

		  Mat4D rx = Identity(); 
		  Mat4D ry = Identity(); 
      Mat4D rz = Identity(); 
		
      x = (float)M_PI * x / 180;
		  y = (float)M_PI * y / 180;
		  z = (float)M_PI * z / 180;

      rx.SetValueAt(1, 1, cos(x));
      rx.SetValueAt(1, 2, -sin(x));
      rx.SetValueAt(2, 1, sin(x));
      rx.SetValueAt(2, 2, cos(x));

      ry.SetValueAt(0, 0, cos(y));
      ry.SetValueAt(0, 2, sin(y));
      ry.SetValueAt(2, 0, -sin(y));
      ry.SetValueAt(2, 2, cos(y));

      rz.SetValueAt(0, 0, cos(z));  
      rz.SetValueAt(0, 1, -sin(z));
      rz.SetValueAt(1, 0, sin(z));
      rz.SetValueAt(1, 1, cos(z));

      return rz * (ry * rx);
    }

    static Mat4D Perspective(float fov, float aspectRatio, float zNear, float zFar){ 
      Mat4D r = Identity();
      float tanHalfFOV = tan(fov/2);
      float zRange = zNear - zFar;
      r.SetValueAt(0, 0, 1.0f / (tanHalfFOV * aspectRatio));
      r.SetValueAt(1, 1, 1.0f / tanHalfFOV);
      r.SetValueAt(2, 2, (-zNear -zFar)/zRange);
      return r;
    }

    static Mat4D Orthographic(float left, float right, float bottom, float top, float near, float far){
      Mat4D r = Identity();
      float width = right - left;
      float height = top - bottom;
      float depth = far - near;

      r.SetValueAt(0, 0, 1.0f / width);
      r.SetValueAt(0, 3, -(right + left) / width);
      r.SetValueAt(1, 1, 2.0f / height);
      r.SetValueAt(1, 3, -(top + bottom) / height);
      r.SetValueAt(2, 2, -2.0f / depth);
      r.SetValueAt(2, 3, -(far + near) / depth);

      return r;
    }

};

#endif