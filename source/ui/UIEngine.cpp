#include "ui/UIEngine.hpp"


UIEngine::UIEngine(int windowWidth, int windowHeight){
  window = new Window(windowWidth, windowHeight, "3DGE");
  keyboard = Keyboard::Create(window->GetWindow());
  mouse = Mouse::Create(window->GetWindow());
}
UIEngine::~UIEngine(){
  delete(window);
  delete(keyboard);
  delete(mouse);
}

bool UIEngine::IsRunning(){
  return window->IsRunning();
}

void UIEngine::Update(){
  mouse->Update();
  window->Update();
}

void UIEngine::Render(){
  window->Render();
}

InputState UIEngine::GetInputState(){
  InputState state(
    keyboard->GetPressedKeys(), 
    mouse->GetX(),
    mouse->GetY(),
    mouse->GetDragX(),
    mouse->GetDragY(),
    mouse->GetScrollX(),
    mouse->GetScrollY(),
    mouse->GetDownButtons()
  );
  return state;
}