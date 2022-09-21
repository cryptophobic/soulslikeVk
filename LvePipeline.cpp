//
// Created by dmitr on 21.09.2022.
//

#include "LvePipeline.h"

//std
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cstring>

namespace lve {

    LvePipeline::LvePipeline(const std::string &vertFilePath, const std::string &fragFilePath) {
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }

    std::vector<char> LvePipeline::readFile(const std::string &filePath) {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};
//        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        if (!file.is_open()) {
            if (file.fail()) {
                std::cout << "fdssd";
            }
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), static_cast<std::streamsize>(fileSize));

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
    }
} // lve