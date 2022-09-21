#ifndef SOULSLIKEVK_LVEPIPELINE_H
#define SOULSLIKEVK_LVEPIPELINE_H

// std
#include <string>
#include <vector>

namespace lve {

    class LvePipeline {
    public:
        LvePipeline(const std::string& vertFilePath, const std::string& fragFilePath);
    private:
        static std::vector<char> readFile(const std::string& filePath);
        void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
    };

} // lve

#endif //SOULSLIKEVK_LVEPIPELINE_H
