#include "LveWindow.h"

#include <utility>

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
}