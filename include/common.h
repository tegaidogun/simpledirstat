#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

struct FileInfo {
    std::string path;  // Ensure this stores the full path
    uintmax_t size;

    bool operator>(const FileInfo& other) const {
        return size > other.size;  // Max-Heap comparison
    }
};

std::string format_size(uintmax_t size);

#endif // COMMON_H
