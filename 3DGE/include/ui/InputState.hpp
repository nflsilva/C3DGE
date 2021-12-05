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

    static const int KEY_0 = 48;
    static const int KEY_1 = 49;
    static const int KEY_2 = 50;
    static const int KEY_3 = 51;
    static const int KEY_4 = 52;
    static const int KEY_5 = 53;
    static const int KEY_6 = 54;
    static const int KEY_7 = 55;
    static const int KEY_8 = 56;
    static const int KEY_9 = 57;
    static const int KEY_A = 65;
    static const int KEY_B = 66;
    static const int KEY_C = 67;
    static const int KEY_D = 68;
    static const int KEY_E = 69;
    static const int KEY_F = 70;
    static const int KEY_G = 71;
    static const int KEY_H = 72;
    static const int KEY_I = 73;
    static const int KEY_J = 74;
    static const int KEY_K = 75;
    static const int KEY_L = 76;
    static const int KEY_M = 77;
    static const int KEY_N = 78;
    static const int KEY_O = 79;
    static const int KEY_P = 80;
    static const int KEY_Q = 81;
    static const int KEY_R = 82;
    static const int KEY_S = 83;
    static const int KEY_T = 84;
    static const int KEY_U = 85;
    static const int KEY_V = 86;
    static const int KEY_W = 87;
    static const int KEY_X = 88;
    static const int KEY_Y = 89;
    static const int KEY_Z = 90;
    static const int KEY_RIGHT = 262;
    static const int KEY_LEFT = 263;
    static const int KEY_DOWN = 264;
    static const int KEY_UP = 265;

};

#endif