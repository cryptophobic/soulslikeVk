#pragma once

#include "utils/FileSystemHelper.hpp"
#include "LveWindow.hpp"
#include "LvePipeline.hpp"
#include "LveSwapChain.hpp"
#include "LveDevice.hpp"
#include "LveModel.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
    class FirstApp {
    public:
        static constexpr int WIDTH = 1600;
        static constexpr int HEIGHT = 1200;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp&) = delete;
        FirstApp &operator=(const FirstApp&) = delete;

        void run();

    private:
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        void sierpinski(std::vector<LveModel::Vertex> &vertices,
                        int depth,
                        glm::vec2 left,
                        glm::vec2 right,
                        glm::vec2 top);

        LveWindow lveWindow{WIDTH, HEIGHT, "Murka window"};
        LveDevice lveDevice{lveWindow};
        LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<LveModel> lveModel;
    };
}