#include "visualizer.h"

void display_directory(const std::vector<FileInfo>& files) {
    for (const FileInfo& file : files) {
        std::cout << file.path << " " << format_size(file.size) << std::endl;
    }
}
