#pragma once

#include "utils/FileSystemHelper.hpp"
#include "LveWindow.hpp"
#include "LveDevice.hpp"
#include "LveGameObject.hpp"
#include "LveRenderer.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
    class FirstApp {
    public:
        static constexpr int WIDTH = 1024;
        static constexpr int HEIGHT = 768;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp&) = delete;
        FirstApp &operator=(const FirstApp&) = delete;

        void run();

    private:
        void loadGameObjects();

        LveWindow lveWindow{WIDTH, HEIGHT, "Murka window"};
        LveDevice lveDevice{lveWindow};
        LveRenderer lveRenderer{lveWindow, lveDevice};

        std::vector<LveGameObject> gameObjects;
    };
}
