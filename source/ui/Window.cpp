#include "tools/Log.hpp"
#include "ui/Window.hpp"

Window::Window(int width, int height, std::string title) : width(width), height(height), title(title) {

  if (!glfwInit())
  {
    Log::E("Failed to init GLFW.");
    exit(1);
  }
  int vMajor, vMinor, vRevision;
  glfwGetVersion (&vMajor, &vMinor, &vRevision);
  Log::I("GLFW version " + std::to_string(vMajor) + "." + std::to_string(vMinor) + "."+ std::to_string(vRevision));

  glfwSetErrorCallback(ErrorCallback);

  window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
  if (!window)
  {
    Log::E("Failed to create GLFW window.");
    exit(1);
  }
  glfwSetWindowCloseCallback(window, CloseCallback);

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
}

Window::~Window(){
  if(window) 
    glfwDestroyWindow(window);
  glfwTerminate();
}

bool Window::IsRunning(){
  return !glfwWindowShouldClose(window);
}

void Window::Update(){
  glfwPollEvents();
}

void Window::Render(){
  glfwSwapBuffers(window);
}

void Window::ErrorCallback(int error, const char* description)
{
  Log::E(std::to_string(error) + " " + std::string(description));
}

void Window::CloseCallback(GLFWwindow* window)
{
  glfwSetWindowShouldClose(window, GLFW_TRUE);
}

