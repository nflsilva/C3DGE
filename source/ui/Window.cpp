#include "tools/Log.hpp"
#include "ui/Window.hpp"

Window* Window::instance = NULL;

Window* Window::Create(int width, int height, std::string title){
  if(instance == NULL){
    instance = new Window(width, height, title);
    instance->keyboard = Keyboard::Create(instance->window);
    instance->mouse = Mouse::Create(instance->window);
  }
  return instance;
}

void Window::Close(){
  delete(instance);
}

Window::Window(int width, int height, std::string title) : width(width), height(height), title(title) {

  if (!glfwInit())
  {
    Log::E("Failed to init GLFW.");
    exit(1);
  }
  glfwSetErrorCallback(ErrorCallback);

  window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
  if (!window)
  {
    Log::E("Failed to create window.");
    exit(1);
  }
  glfwSetWindowCloseCallback(window, CloseCallback);

  glfwMakeContextCurrent(window);

}

Window::~Window(){
  if(window){ glfwDestroyWindow(window); }
  glfwTerminate();
}

Keyboard* Window::GetKeyboard(){
  return keyboard;
}

Mouse* Window::GetMouse(){
  return mouse;
}

bool Window::IsRunning(){
  return !glfwWindowShouldClose(window);
}

void Window::Update(){
  keyboard->Update();
  mouse->Update();
  glfwPollEvents();
}

void Window::ErrorCallback(int error, const char* description)
{
  Log::E(std::to_string(error) + " " + std::string(description));
}

void Window::CloseCallback(GLFWwindow* window)
{
  glfwSetWindowShouldClose(window, GLFW_TRUE);
}

