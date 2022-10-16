#include <iostream>
#include "FileSystemHelper.hpp"

std::string FileSystemHelper::root;

std::string FileSystemHelper::getPath(const std::string &path) {
    return root + std::string("/") + path;
}

void FileSystemHelper::setApplicationPath(std::string path) {
    boost::replace_all(path,"./", "");
    const fs::path fullApplicationPath = fs::absolute(fs::path(path));
    root = fullApplicationPath.parent_path().parent_path().string();
    std::cout << root << " set" << std::endl;
}
