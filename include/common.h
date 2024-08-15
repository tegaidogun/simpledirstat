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

// Declare the utility function
std::string format_size(uintmax_t size);

#endif // COMMON_H
