#pragma once

#include "LveWindow.h"
#include "LvePipeline.h"
#include "utils/FileSystemHelper.h"

namespace lve {
    class FirstApp {
    public:
        static constexpr int WIDTH = 1600;
        static constexpr int HEIGHT = 1200;

        void run();

    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "Murka window"};
        LvePipeline lvePipeline{
            FileSystemHelper::getPath("shaders/simpleShader.vert.spv"),
            FileSystemHelper::getPath("shaders/simpleShader.frag.spv")
        };
    };
}