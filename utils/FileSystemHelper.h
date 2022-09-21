//
// Created by dmitr on 21.09.2022.
//

#ifndef SOULSLIKEVK_FILESYSTEMHELPER_H
#define SOULSLIKEVK_FILESYSTEMHELPER_H

#include <string>
#include <filesystem>
#include <boost/algorithm/string.hpp>

namespace fs = std::filesystem;

class FileSystemHelper
{

public:
    static std::string getPath(const std::string& path);
    static void setApplicationPath(std::string path);

private:
    static std::string root;
};


#endif //SOULSLIKEVK_FILESYSTEMHELPER_H
