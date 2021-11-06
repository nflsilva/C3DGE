#include "tools/Log.hpp"
#include "ui/Mouse.hpp"


Mouse* Mouse::instance = NULL;

Mouse::Mouse(GLFWwindow* window) : x(0), y(0),clickX(0),clickY(0), scrollX(0), scrollY(0){}
Mouse::~Mouse(){}

Mouse* Mouse::Create(GLFWwindow* window){
  if(instance == NULL){
    instance = new Mouse(window);
    glfwSetCursorPosCallback(window, Mouse::MousePositionCallback);
    glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
    glfwSetScrollCallback(window, Mouse::MouseScrollCallback);
  }
  return instance;
}
void Mouse::Update(){
  scrollX = 0;
  scrollY = 0;
}

bool Mouse::IsButton(int key){
  return downButtons.find(key) != downButtons.end();
}

bool Mouse::IsButtonDown(int key){
  return downButtons.find(key) != downButtons.end();;
}

bool Mouse::IsButtonUp(int key){
  return upButtons.find(key) != upButtons.end();
}

int Mouse::GetX(){
  return x;
}

int Mouse::GetY(){
  return y;
}

int Mouse::GetDragX(){
  return clickX - x;
}

int Mouse::GetDragY(){
  return clickY - y;
}

int Mouse::GetScrollX(){
  return scrollX;
}
int Mouse::GetScrollY(){
  return scrollY;
}

std::unordered_set<int> Mouse::GetDownButtons(){
  return downButtons;
}

void Mouse::MousePositionCallback(GLFWwindow* window, double xpos, double ypos){
  Mouse::instance->x = (int)xpos;
  Mouse::instance->y = (int)ypos;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods){
  Mouse* i = Mouse::instance;
  switch (action){
  case GLFW_PRESS:
    i->downButtons.insert(button);
    i->clickX = i->x;
    i->clickY = i->y;
    break;
  case GLFW_RELEASE:
    i->downButtons.erase(button);
    break;
  default:
    break;
  }
}

void Mouse::MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset){
  Mouse::instance->scrollX = (int)xoffset;
  Mouse::instance->scrollY = (int)yoffset;
}
