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
        bool wasWindowResized();
        void resetWindowResizeFlag();
    private:
        static void framebufferResizedCallback(GLFWwindow* wwindow, int width, int height);

        void initWindow();

        int width;
        int height;
        bool framebufferResized = false;

        std::string name;

        // TODO: make this pointer smarter
        GLFWwindow *window = nullptr;
    };
}
