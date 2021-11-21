#ifndef RENDER_ENGINE_HPP
#define RENDER_ENGINE_HPP

#include <GL/glew.h>
#include <unordered_map>

#include "core/GameObject.hpp"
#include "render/projection/PerspectiveProjection.hpp"
#include "render/BaseCamera.hpp"
#include "ui/InputState.hpp"

class RenderEngine {
  private:
    int screenWidth, screenHeight;
    PerspectiveProjection* projection;
    BaseCamera* camera;

    void ClearScreen();

  public:
    RenderEngine(int screenWidth, int screenHeight);
    ~RenderEngine();

    void Init();
    void Render(std::list<GameObject*> models);

    void Update(float elapsedTime);
    void Input(InputState input);
    void SetCamera(BaseCamera* camera);

};

#endif