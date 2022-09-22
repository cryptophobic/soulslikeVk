#pragma once

#include "LveWindow.hpp"
#include "LvePipeline.hpp"
#include "utils/FileSystemHelper.hpp"
#include "LveDevice.hpp"


namespace lve {
    class FirstApp {
    public:
        static constexpr int WIDTH = 1600;
        static constexpr int HEIGHT = 1200;

        void run();

    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "Murka window"};
        LveDevice lveDevice{lveWindow};
        LvePipeline lvePipeline{
            lveDevice,
            FileSystemHelper::getPath("shaders/simpleShader.vert.spv"),
            FileSystemHelper::getPath("shaders/simpleShader.frag.spv"),
            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
        };
    };
}