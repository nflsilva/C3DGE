#include "ui/UIEngine.hpp"


UIEngine::UIEngine(int windowWidth, int windowHeight){
  window = Window::Create(windowWidth, windowHeight, "3DGE");
  keyboard = window->GetKeyboard();
  mouse = window->GetMouse();
}
UIEngine::~UIEngine(){

}

bool UIEngine::IsRunning(){
  return window->IsRunning();
}

void UIEngine::Update(){
  keyboard->Update();
  mouse->Update();
  window->Update();
}

void UIEngine::Render(){
  window->Render();
}

void UIEngine::Close(){
  window->Close();
}