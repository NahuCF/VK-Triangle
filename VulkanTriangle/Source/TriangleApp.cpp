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

    CreateInstance();
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
    vkDestroyInstance(m_VkInstance, nullptr);

    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void TriangleApp::CreateInstance()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = m_WindowName.c_str();
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    m_ExtensionsGLFW = glfwGetRequiredInstanceExtensions(&m_ExtensionCount);

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = m_ExtensionCount;
    createInfo.ppEnabledExtensionNames = m_ExtensionsGLFW;
    createInfo.enabledLayerCount = 0;

    if(vkCreateInstance(&createInfo, nullptr, &m_VkInstance) != VK_SUCCESS)
        throw std::runtime_error("failed to create instance!");
}