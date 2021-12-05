#include "render/RenderEngine.hpp"
#include "core/GameObject.hpp"
#include "tools/Log.hpp"
#include "tools/Time.hpp"

RenderEngine::RenderEngine(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {
  projection = new PerspectiveProjection((float)screenWidth, (float)screenHeight, 70.0F, 0.1F, 1000.0F);
}

RenderEngine::~RenderEngine(){
  if(projection) delete(projection);
  if(camera) delete(camera);
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
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

}

void RenderEngine::Render(std::list<GameObject*> objects, std::list<DirectionalLight*> lights){
  ClearScreen();

  for(auto o : objects){
    BaseModel* m = o->GetModel();
    Mesh* mesh = m->GetMesh();
    Texture* texture = m->GetTexture();
    Shader* shader = m->GetShader();

    shader->Bind();
    shader->SetModelMatrix(o->GetModelMatrix());
    shader->SetViewMatrix(camera->GetViewMatrix());
    shader->SetProjectionMatrix(projection->GetProjectionMatrix());

    if(lights.size() > 0){
      DirectionalLight* light = lights.front();
      shader->SetLightDirection(light->GetDirection());
      shader->SetLightColor(light->GetColor());
    }

    texture->Bind(0);
    
    mesh->Render();

    texture->Unbind();
    shader->Unbind();
  }

}

void RenderEngine::Update(float elapsedTime, InputState input){
  if(camera) camera->Update(elapsedTime, input);
}
void RenderEngine::SetCamera(BaseCamera* camera) {
  this->camera = camera;
}

void RenderEngine::ClearScreen() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
