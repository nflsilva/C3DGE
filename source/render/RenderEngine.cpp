#include "render/RenderEngine.hpp"
#include "render/BaseModel.hpp"
#include "tools/Log.hpp"
#include "tools/Time.hpp"

RenderEngine::RenderEngine(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {
  projection = new PerspectiveProjection((float)screenWidth, (float)screenHeight, 70.0F, 0.1F, 1000.0F);
}

RenderEngine::~RenderEngine(){

}

void RenderEngine::Init(){

  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    Log::E(std::string((char*)glewGetErrorString(err)));
    exit(1);
  }
  Log::I("GLEW version " + std::string((char*)glewGetString(GLEW_VERSION)));

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);

}

void RenderEngine::Render(std::list<BaseModel*> models){
  ClearScreen();
  for(auto m : models){
    Mesh* mesh = m->GetMesh();
    Texture* texture = m->GetTexture();
    Shader* shader = m->GetShader();

    shader->Bind();
    shader->SetMVPMatrix(projection->GetProjection() * camera->GetViewMatrix());
    texture->Bind(0);
    
    mesh->Render();

    texture->Unbind();
    shader->Unbind();
  }
}

void RenderEngine::Update(float elapsedTime){
  if(camera) camera->Update(elapsedTime);

}

void RenderEngine::Input(InputState input){
  if(camera) camera->Input(input);

}
void RenderEngine::SetCamera(BaseCamera* camera) {
  this->camera = camera;
}

void RenderEngine::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
