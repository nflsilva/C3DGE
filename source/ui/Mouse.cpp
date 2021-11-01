#include "tools/Log.hpp"
#include "ui/Mouse.hpp"


Mouse* Mouse::instance = NULL;

Mouse::Mouse(GLFWwindow* window){}

Mouse* Mouse::Create(GLFWwindow* window){
  if(instance == NULL){
    instance = new Mouse(window);
    glfwSetCursorPosCallback(window, Mouse::MousePositionCallback);
    glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
  }
  return instance;
}

bool Mouse::GetButton(int key){
  return downButtons.find(key) != downButtons.end();
}

bool Mouse::GetButtonDown(int key){
  return downButtons.find(key) != downButtons.end();;
}

bool Mouse::GetButtonUp(int key){
  return upButtons.find(key) != upButtons.end();
}

Vec2Di_t Mouse::GetPosition(){
  return position;
}

void Mouse::MousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
  Mouse::instance->position.x = (int)xpos;
  Mouse::instance->position.y = (int)ypos;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods){
  switch (action)
  {
  case GLFW_PRESS:
    Mouse::instance->downButtons.insert(button);
    break;
  case GLFW_RELEASE:
    Mouse::instance->upButtons.insert(button);
    break;
  default:
    break;
  }
}

void Mouse::Update(){
  downButtons.clear();
  upButtons.clear();
}
