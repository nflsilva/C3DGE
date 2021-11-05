#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

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
        Builder AddGeometry(std::vector<Vertex> vertices, std::vector<int> indices){
          RenderComponent* rc = new RenderComponent();
          rc->CreateGeometry(vertices, indices);
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