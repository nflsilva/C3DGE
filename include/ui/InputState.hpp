#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <unordered_set>

class InputState {

  public:
    InputState(){};

    std::unordered_set<int> isCurrentKey; 
    std::unordered_set<int> isDownKeys;
    std::unordered_set<int> isUpKeys;

    int mouseX;
    int mouseY;
    std::unordered_set<int> isMouseDown;
    std::unordered_set<int> isMouseUp;

    static bool ContainsKey(std::unordered_set<int>* set, int key){
      std::unordered_set<int>::iterator it = set->find(key);
      return it != set->end();
    }

};

#endif