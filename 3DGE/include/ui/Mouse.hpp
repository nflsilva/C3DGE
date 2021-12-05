#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <GLFW/glfw3.h>
#include <unordered_set>

class Mouse {

  private:
    static Mouse* instance;
    int x;
    int y;
    int clickX;
    int clickY;
    int scrollX;
    int scrollY;
    std::unordered_set<int> downButtons;
    std::unordered_set<int> upButtons;

    Mouse(GLFWwindow* window);
    
    static void MousePositionCallback(GLFWwindow* window, double xpos, double ypos);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

  public:
    static Mouse* Create(GLFWwindow* window);
    ~Mouse();

    Mouse(Mouse &other) = delete;
    void operator=(const Mouse &) = delete;

    void Update();

    bool IsButton(int button);
    bool IsButtonDown(int button);
    bool IsButtonUp(int button);
    int GetX();
    int GetY();
    int GetDragX();
    int GetDragY();
    int GetScrollX();
    int GetScrollY();
    std::unordered_set<int> GetDownButtons();

};

#endif