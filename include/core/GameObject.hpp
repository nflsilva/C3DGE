#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "tools/Resources.hpp"
#include "render/RenderComponent.hpp"

class GameObject {
  public:
    std::list<RenderComponent*> renderComponents;
    GameObject(){};

  public:
    class Builder {
      private:
        GameObject* instance;
      public:
        Builder(){ instance = new GameObject(); }
        Builder AddGeometry(Resources::MeshData md){
          RenderComponent* rc = new RenderComponent();
          rc->CreateGeometry(md.vertices, md.textureCoordinates, md.colors, md.normals, md.indices);
          instance->renderComponents.push_front(rc);
          return *this;
        }
        Builder AddTexture(std::string fileName){
          instance->renderComponents.front()->CreateTexture(fileName);
          return *this;
        }
        GameObject* Build(){
          return instance;
        }
    };

    ~GameObject(){
      for(auto c : renderComponents){ delete(c);}
    }

};

#endif