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
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizedCallback);
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

    bool LveWindow::wasWindowResized() {
        return framebufferResized;
    }

    void LveWindow::resetWindowResizeFlag() {
        framebufferResized = false;
    }

    void LveWindow::framebufferResizedCallback(GLFWwindow *wwindow, int width, int height) {
        auto lveWindow = reinterpret_cast<LveWindow *>(glfwGetWindowUserPointer(wwindow));
        lveWindow->framebufferResized = true;
        lveWindow->width = width;
        lveWindow->height = height;
    }
}