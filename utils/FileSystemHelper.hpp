#pragma once

#include <string>
#include <filesystem>
#include <boost/algorithm/string.hpp>

namespace fs = std::filesystem;

class FileSystemHelper
{

public:
    static std::string getPath(const std::string &path);
    static void setApplicationPath(std::string path);

private:
    static std::string root;
};
