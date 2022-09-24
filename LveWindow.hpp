#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

namespace lve {
    class LveWindow {
    public:
        LveWindow(int windowWidth, int windowHeight, std::string windowName);
        ~LveWindow();

        LveWindow(const LveWindow &) = delete;
        LveWindow &operator=(const LveWindow &) = delete;

        bool shouldClose();
        VkExtent2D getExtent();

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    private:

        void initWindow();

        const int width;
        const int height;

        std::string name;

        // TODO: make this pointer smarter
        GLFWwindow *window = nullptr;
    };
}
