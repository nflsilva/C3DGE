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
    
    static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

  public:
    static Keyboard* Create(GLFWwindow* window);
    ~Keyboard();

    Keyboard(Keyboard &other) = delete;
    void operator=(const Keyboard &) = delete;

    bool IsKey(int key);
    bool IsKeyDown(int key);
    bool IsKeyUp(int key);

    std::unordered_set<int> GetCurrentKeys();
    std::unordered_set<int> GetDownKeys();
    std::unordered_set<int> GetUpKeys();

    void Update();

};

#endif