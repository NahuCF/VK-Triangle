#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "TriangleApp.h"
#include "glm.hpp"

int main() 
{
    TriangleApp app(glm::vec2(800, 600), "Hello World in Vulkan");

    try 
    {
        app.Run();
    }
    catch(const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}