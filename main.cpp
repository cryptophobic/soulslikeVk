#include "FirstApp.h"
#include "utils/FileSystemHelper.h"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>


int main (int argc, char* argv[]) {

    FileSystemHelper::setApplicationPath(std::string(argv[0]));

    std::fstream file;
    file.open(FileSystemHelper::getPath("shaders/simpleShader.vert.spv"));
    if (file.fail()) {
        return EXIT_FAILURE;
    }


    lve::FirstApp app{};

    try {
        app.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}