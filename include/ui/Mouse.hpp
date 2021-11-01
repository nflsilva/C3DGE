#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <GLFW/glfw3.h>
#include <unordered_set>
#include "ui/Keyboard.hpp"
#include "tools/Vec2D.hpp"

class Mouse {

  private:
    static Mouse* instance;
    Vec2Di_t position;
    std::unordered_set<int> downButtons;
    std::unordered_set<int> upButtons;

    Mouse(GLFWwindow* window);
    ~Mouse();
    
    static void MousePositionCallback(GLFWwindow* window, double xpos, double ypos);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  public:
    static Mouse* Create(GLFWwindow* window);

    Mouse(Mouse &other) = delete;
    void operator=(const Mouse &) = delete;

    bool GetButton(int button);
    bool GetButtonDown(int button);
    bool GetButtonUp(int button);
    Vec2Di_t GetPosition();

    void Update();

};

#endif