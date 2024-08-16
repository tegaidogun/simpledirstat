#include "visualizer.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void displayDirectories(const std::map<fs::path, uintmax_t>& directorySizes, uintmax_t totalSize) {
    std::cout << "Directory - Size\n";
    // Convert map to a vector and sort by size
    std::vector<std::pair<fs::path, uintmax_t>> sortedDirectories(directorySizes.begin(), directorySizes.end());
    std::sort(sortedDirectories.begin(), sortedDirectories.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Sort descending by size
    });

    for (const auto& [dir, size] : sortedDirectories) {
        std::cout << dir.filename().string() << " - " << format_size(size) << "\n";
    }
}

void displayFiles(const std::vector<FileInfo>& files) {
    std::cout << "File Name - File Size - File Path\n";
    for (const auto& file : files) {
        std::filesystem::path path(file.path);
        std::string displayPath = path.string();
        std::string homePath = std::getenv("HOME"); // Get the home directory path
        if (!homePath.empty() && displayPath.find(homePath) == 0) {
            // Replace the home directory path with ~
            displayPath.replace(0, homePath.length(), "~");
        }
        std::cout << std::setw(30) << std::left << path.filename().string() 
                  << " - " << std::setw(12) << std::left << format_size(file.size) 
                  << " - " << displayPath << "\n";
    }
}

void displayFileTypeSummary(const std::map<std::string, std::pair<size_t, uintmax_t>>& fileTypeSummary, size_t n) {
    std::cout << "File Type - Amount - Total Size\n";
    // Sort file types by total size
    std::vector<std::pair<std::string, std::pair<size_t, uintmax_t>>> sortedTypes(fileTypeSummary.begin(), fileTypeSummary.end());
    std::sort(sortedTypes.begin(), sortedTypes.end(), [](const auto& a, const auto& b) {
        return a.second.second > b.second.second; // Sort by total size
    });

    size_t count = 0;
    for (const auto& [type, info] : sortedTypes) {
        if (++count > n && n != std::numeric_limits<size_t>::max()) break;
        std::cout << type << " - " << info.first << " - " << format_size(info.second) << "\n";
    }
}
