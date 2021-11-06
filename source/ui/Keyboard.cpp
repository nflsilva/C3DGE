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

bool Keyboard::IsKeyPressed(int key){
  return pressedKeys.find(key) != pressedKeys.end();
}

std::unordered_set<int> Keyboard::GetPressedKeys(){
  return pressedKeys;
};

void Keyboard::KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  switch (action)
  {
  case GLFW_PRESS:
    Keyboard::instance->pressedKeys.insert(key);
    break;
  case GLFW_RELEASE:
    Keyboard::instance->pressedKeys.erase(key);
    break;
  default:
    break;
  }
}
