#include <iostream>
#include <string>

#include "vulkan/vulkan.h"
#include "vec2.hpp"

#define GLFW_INCLUDE_VULKAN
#include <glfw3.h>

class TriangleApp
{
public:
    TriangleApp(glm::vec2 windowSize, std::string windowName);
    void Run();

private:
    void InitVulkan();
    void MainLoop();
    void Cleanup();

    void CreateInstance();
private:
    GLFWwindow* m_Window;
    std::string m_WindowName;
    glm::vec2 m_WindowSize;

    VkInstance m_VkInstance;
    uint32_t m_ExtensionCount;
    const char** m_ExtensionsGLFW;
};