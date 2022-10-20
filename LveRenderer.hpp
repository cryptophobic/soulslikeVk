#pragma once

#include "utils/FileSystemHelper.hpp"
#include "LveWindow.hpp"
#include "LveSwapChain.hpp"
#include "LveDevice.hpp"

// std
#include <cassert>
#include <memory>
#include <vector>

namespace lve {
    class LveRenderer {
    public:

        LveRenderer(LveWindow &window, LveDevice &device);
        ~LveRenderer();

        LveRenderer(const LveRenderer &) = delete;
        LveRenderer &operator=(const LveRenderer &) = delete;

        VkRenderPass getSwapChainRenderPass() const;
        float getAspectRatio() const;
        bool isFrameInProgress() const;

        VkCommandBuffer getCurrentCommandBuffer() const;

        int getFrameIndex() const;

        VkCommandBuffer beginFrame();
        void endFrame();

        void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
        void endSwapChainRenderPass(VkCommandBuffer commandBuffer);

    private:
        void createCommandBuffers();
        void freeCommandBuffers();
        void recreateSwapChain();

        LveWindow &lveWindow;
        LveDevice &lveDevice;
        std::unique_ptr<LveSwapChain> lveSwapChain;
        std::vector<VkCommandBuffer> commandBuffers;

        uint32_t currentImageIndex{0};
        int currentFrameIndex{0};
        bool isFrameStarted{false};
    };
}
