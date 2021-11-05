#include "ui/UIEngine.hpp"


UIEngine::UIEngine(int windowWidth, int windowHeight){
  window = new Window(windowWidth, windowHeight, "3DGE");
  keyboard = Keyboard::Create(window->GetWindow());
  //mouse = window->GetMouse();
}
UIEngine::~UIEngine(){
  delete(window);
  delete(keyboard);
  //delete(mouse);
}

bool UIEngine::IsRunning(){
  return window->IsRunning();
}

void UIEngine::Update(){
  keyboard->Update();
  //mouse->Update();
  window->Update();
}

void UIEngine::Render(){
  window->Render();
}

InputState UIEngine::GetInputState(){
  InputState state;
  
  state.isCurrentKey = keyboard->GetCurrentKeys();
  state.isDownKeys = keyboard->GetDownKeys();
  state.isUpKeys = keyboard->GetUpKeys();

  return state;
}