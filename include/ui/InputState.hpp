#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <unordered_set>

class InputState {
  private:
    std::unordered_set<int> pressedKeys; 
    int mouseX;
    int mouseY;
    int mouseDragDeltaX;
    int mouseDragDeltaY;
    int scrollX;
    int scrollY;
    std::unordered_set<int> mouseButtonDown;

  public:
    InputState(
      std::unordered_set<int> pressedKeys, 
      int mouseX, 
      int mouseY, 
      int deltaX, 
      int deltaY,
      int scrollX,
      int scrollY,
      std::unordered_set<int> mouseButtonDown): 
    pressedKeys(pressedKeys), 
    mouseX(mouseX), 
    mouseY(mouseY), 
    mouseDragDeltaX(deltaX), 
    mouseDragDeltaY(deltaY),
    scrollX(scrollX),
    scrollY(scrollY),
    mouseButtonDown(mouseButtonDown){};

    bool IsKeyPressed(int key){
      return pressedKeys.find(key) != pressedKeys.end();
    }
    bool IsMousePressed(int button){
      return mouseButtonDown.find(button) != mouseButtonDown.end();
    }
    int GetDragDeltaX(){
      return mouseDragDeltaX;
    }
    int GetDragDeltaY(){
      return mouseDragDeltaY;
    }
    bool DidYScrollUp(){
      return scrollY > 0;
    }
    bool DidYScrollDown(){
      return scrollY < 0;
    }

};

#endif