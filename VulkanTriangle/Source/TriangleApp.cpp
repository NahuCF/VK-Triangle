#include "TriangleApp.h"

TriangleApp::TriangleApp(glm::vec2 windowSize, std::string windowName)
{
    m_WindowSize = windowSize;
    m_WindowName = windowName;
}

void TriangleApp::Run()
{
    InitVulkan();
    MainLoop();
    Cleanup();
}

void TriangleApp::InitVulkan()
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_Window = glfwCreateWindow(m_WindowSize.x, m_WindowSize.y, m_WindowName.c_str(), nullptr, nullptr);
}

void TriangleApp::MainLoop()
{
    while(!glfwWindowShouldClose(m_Window)) 
    {
        glfwPollEvents();
    }
}

void TriangleApp::Cleanup()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}