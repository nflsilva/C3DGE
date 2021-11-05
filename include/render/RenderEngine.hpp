#ifndef RENDER_ENGINE_HPP
#define RENDER_ENGINE_HPP

#include <GL/glew.h>
#include <unordered_map>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "render/RenderComponent.hpp"
#include "render/ShaderProgram.hpp"
#include "render/Camera.hpp"

class RenderEngine {
  private:
    
    float zNear;
    float zFar;
    float fov;
    int width;
    int height;

    Camera* camera;
    glm::mat4 projectionMatrix;
    std::unordered_map<int, ShaderProgram*> shaders;

    void CreateShaders();

  public:
    RenderEngine(int width, int height);
    ~RenderEngine();
    void Init();
    void Render(std::list<RenderComponent*> components);
    void ClearScreen();

    void MoveCameraLeft();
    void MoveCameraRight();
    void MoveCameraFoward();
    void MoveCameraBackwards();
    void RotateCameraLeft();
};

#endif