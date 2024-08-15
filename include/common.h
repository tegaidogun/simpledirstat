#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

struct FileInfo {
    fs::path path;
    uintmax_t size;
};

// A utility to convert sizes from bytes to human-readable format
std::string format_size(uintmax_t size) {
    std::vector<std::string> sizes = {"B", "KB", "MB", "GB", "TB"};
    int order = 0;
    double formattedSize = size;
    while (formattedSize >= 1024 && order < sizes.size() - 1) {
        order++;
        formattedSize /= 1024;
    }
    return std::to_string(formattedSize) + ' ' + sizes[order];
}

#endif // COMMON_H
