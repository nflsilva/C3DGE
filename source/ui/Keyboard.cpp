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

bool Keyboard::IsKey(int key){
  return currentKeys.find(key) != currentKeys.end();

}
bool Keyboard::IsKeyDown(int key){
  return downKeys.find(key) != downKeys.end();;
}
bool Keyboard::IsKeyUp(int key){
  return upKeys.find(key) != upKeys.end();
}

std::unordered_set<int> Keyboard::GetCurrentKeys(){
  return currentKeys;
};
std::unordered_set<int> Keyboard::GetDownKeys(){
  return downKeys;
};
std::unordered_set<int> Keyboard::GetUpKeys(){
  return upKeys;
};

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
