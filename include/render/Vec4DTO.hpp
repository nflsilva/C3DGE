#ifndef VEC4DTO_HPP
#define VEC4DTO_HPP

class Vec4DTO {
  public:
    float v0, v1, v2, v3;
    Vec4DTO(): v0(0), v1(0), v2(0), v3(0) {}
    Vec4DTO(float v0, float v1) : v0(v0), v1(v1), v2(0), v3(0) {}
    Vec4DTO(float v0, float v1, float v2) : v0(v0), v1(v1), v2(v2), v3(0) {}
    Vec4DTO(float v0, float v1, float v2, float v3) : v0(v0), v1(v1), v2(v2), v3(v3) {}
};

#endif