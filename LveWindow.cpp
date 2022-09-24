#include "LveWindow.hpp"

// std
#include <stdexcept>

namespace lve {

    LveWindow::LveWindow(int windowWidth, int windowHeight, std::string windowName) :
        width(windowWidth),
        height(windowHeight),
        name(std::move(windowName)) {
        initWindow();
    }

    LveWindow::~LveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void LveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    }

    void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create window surface");
        }
    }

    bool LveWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    VkExtent2D LveWindow::getExtent() {
        return {
            static_cast<uint32_t>(width),
            static_cast<uint32_t>(height)
        };
    }
}