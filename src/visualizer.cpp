#include "visualizer.h"

void display_directory(const std::vector<FileInfo>& files) {
    for (const auto& file : files) {
        std::cout << file.path << " " << format_size(file.size) << std::endl;
    }
}
