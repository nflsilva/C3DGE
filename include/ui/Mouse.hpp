#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <GLFW/glfw3.h>
#include <unordered_set>

class Mouse {

  private:
    static Mouse* instance;
    int x;
    int y;
    std::unordered_set<int> downButtons;
    std::unordered_set<int> upButtons;

    Mouse(GLFWwindow* window);
    
    static void MousePositionCallback(GLFWwindow* window, double xpos, double ypos);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  public:
    static Mouse* Create(GLFWwindow* window);
    ~Mouse();

    Mouse(Mouse &other) = delete;
    void operator=(const Mouse &) = delete;

    bool GetButton(int button);
    bool GetButtonDown(int button);
    bool GetButtonUp(int button);
    int GetX();
    int GetY();

    void Update();

};

#endif