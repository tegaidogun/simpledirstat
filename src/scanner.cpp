#include "scanner.h"
#include <algorithm>

FileScanner::FileScanner(size_t maxFiles) : maxFiles(maxFiles) {}

void FileScanner::scanDirectories(const fs::path& rootDirectory) {
    for (const auto& entry : fs::directory_iterator(rootDirectory)) {
        if (fs::is_directory(entry)) {
            uintmax_t totalSize = 0;
            for (const auto& file : fs::recursive_directory_iterator(entry.path())) {
                if (fs::is_regular_file(file)) {
                    totalSize += fs::file_size(file);
                }
            }
            directorySizes[entry.path()] = totalSize;
        }
    }
}

void FileScanner::scanFiles(const fs::path& rootDirectory) {
    for (const auto& entry : fs::recursive_directory_iterator(rootDirectory)) {
        processFile(entry);
    }
    std::sort(files.begin(), files.end(), [](const FileInfo& a, const FileInfo& b) {
        return a.size > b.size;
    });
    if (files.size() > maxFiles) {
        files.resize(maxFiles);
    }
}

void FileScanner::processFile(const fs::directory_entry& entry) {
    if (fs::is_regular_file(entry)) {
        FileInfo info;
        info.path = entry.path().string();  // Store the full path
        info.size = fs::file_size(entry);
        files.push_back(info);
    }
}

std::vector<FileInfo> FileScanner::getFiles() const {
    return files;
}

std::map<fs::path, uintmax_t> FileScanner::getDirectorySizes() const {
    return directorySizes;
}

std::map<std::string, std::pair<size_t, uintmax_t>> FileScanner::getFileTypeSummary() const {
    return fileTypeSizes;
}
