#include "tools/Log.hpp"
#include "ui/Keyboard.hpp"


Keyboard* Keyboard::instance = NULL;

Keyboard::Keyboard(GLFWwindow* window){}
Keyboard::~Keyboard(){};

Keyboard* Keyboard::Create(GLFWwindow* window){
  if(instance == NULL){
    instance = new Keyboard(window);
    glfwSetKeyCallback(window, Keyboard::KeyboardCallback);
  }
  return instance;
}

bool Keyboard::GetKey(int key){
  return currentKeys.find(key) != currentKeys.end();

}
bool Keyboard::GetKeyDown(int key){
  return downKeys.find(key) != downKeys.end();;
}
bool Keyboard::GetKeyUp(int key){
  return upKeys.find(key) != upKeys.end();
}

void Keyboard::KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  switch (action)
  {
  case GLFW_PRESS:
    Keyboard::instance->downKeys.insert(key);
    break;
  case GLFW_REPEAT:
    Keyboard::instance->currentKeys.insert(key);
    break;
  case GLFW_RELEASE:
    Keyboard::instance->upKeys.insert(key);
    break;
  default:
    break;
  }
}

void Keyboard::Update(){
  downKeys.clear();
  currentKeys.clear();
  upKeys.clear();
}
