#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <GLFW/glfw3.h>
#include <unordered_set>

class Keyboard {

  private:
    static Keyboard* instance;

    std::unordered_set<int> currentKeys; 
    std::unordered_set<int> downKeys;
    std::unordered_set<int> upKeys;

    Keyboard(GLFWwindow* window);
    ~Keyboard();
    
    static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

  public:
    static Keyboard* Create(GLFWwindow* window);

    Keyboard(Keyboard &other) = delete;
    void operator=(const Keyboard &) = delete;

    bool GetKey(int key);
    bool GetKeyDown(int key);
    bool GetKeyUp(int key);

    void Update();

};

#endif