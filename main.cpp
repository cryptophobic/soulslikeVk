#include "FirstApp.hpp"
#include "utils/FileSystemHelper.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>


int main (int argc, char* argv[]) {

    FileSystemHelper::setApplicationPath(std::string(argv[0]));
    lve::FirstApp app{};

    try {
        app.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}