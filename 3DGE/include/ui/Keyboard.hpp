#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <GLFW/glfw3.h>
#include <unordered_set>

class Keyboard {

  private:
    static Keyboard* instance;

    std::unordered_set<int> pressedKeys; 

    Keyboard(GLFWwindow* window);
    
    static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

  public:
    static Keyboard* Create(GLFWwindow* window);
    ~Keyboard();

    Keyboard(Keyboard &other) = delete;
    void operator=(const Keyboard &) = delete;

    bool IsKeyPressed(int key);

    std::unordered_set<int> GetPressedKeys();
};

#endif