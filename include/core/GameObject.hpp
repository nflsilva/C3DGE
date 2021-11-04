#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "render/RenderComponent.hpp"

class GameObject {
  public:
    std::list<RenderComponent*> renderComponents;

  public:
    GameObject(){};
    ~GameObject(){
      for(auto c : renderComponents){ delete(c);}
    }

};

#endif