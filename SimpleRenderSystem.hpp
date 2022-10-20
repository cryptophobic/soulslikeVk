#pragma once

#include "utils/FileSystemHelper.hpp"
#include "LveCamera.hpp"
#include "LvePipeline.hpp"
#include "LveDevice.hpp"
#include "LveGameObject.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
    class SimpleRenderSystem {
    public:
        SimpleRenderSystem(LveDevice &device, VkRenderPass renderPass);
        ~SimpleRenderSystem();

        SimpleRenderSystem(const SimpleRenderSystem&) = delete;
        SimpleRenderSystem &operator=(const SimpleRenderSystem&) = delete;
        void renderGameObjects(
                VkCommandBuffer commandBuffer,
                std::vector<LveGameObject> &gameObjects,
                LveCamera &camera);

    private:
        void createPipelineLayout();
        void createPipeline(VkRenderPass renderPass);

        LveDevice &lveDevice;

        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout{};
    };
}
