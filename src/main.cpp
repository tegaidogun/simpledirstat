#include <iostream>
#include <algorithm>
#include <numeric>
#include "scanner.h"
#include "visualizer.h"

int main(int argc, char** argv) {
    fs::path directory = argc > 1 ? argv[1] : fs::current_path();
    FileScanner scanner;

    if (argc == 2) {
        scanner.scanDirectories(directory);
        auto directorySizes = scanner.getDirectorySizes();
        uintmax_t totalSize = std::accumulate(directorySizes.begin(), directorySizes.end(), 0ULL,
                                              [](uintmax_t sum, const auto& pair) { return sum + pair.second; });
        displayDirectories(directorySizes, totalSize);
    } else if (argc >= 3) {
        size_t n = (argc > 3) ? std::stoi(argv[3]) : std::numeric_limits<size_t>::max();
        if (std::string(argv[2]) == "--filetype") {
            scanner.scanFiles(directory);
            auto fileTypeSummary = scanner.getFileTypeSummary();
            displayFileTypeSummary(fileTypeSummary, n);
        } else if (std::string(argv[2]) == "--filesize") {
            scanner.scanFiles(directory);
            auto files = scanner.getFiles();
            if (files.size() > n) files.resize(n); // Properly using 'n'
            displayFiles(files);
        }
    } else {
        std::cerr << "Usage: " << argv[0] << " <directory> [--filetype [n] | --filesize [n]]" << std::endl;
        return 1;
    }
    return 0;
}
