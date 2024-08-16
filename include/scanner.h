#ifndef SCANNER_H
#define SCANNER_H

#include "common.h"
#include <map>
#include <vector>

class FileScanner {
public:
    FileScanner(size_t maxFiles = std::numeric_limits<size_t>::max());
    void scanDirectories(const fs::path& rootDirectory);
    void scanFiles(const fs::path& rootDirectory);
    std::vector<FileInfo> getFiles() const;
    std::map<fs::path, uintmax_t> getDirectorySizes() const;
    std::map<std::string, std::pair<size_t, uintmax_t>> getFileTypeSummary() const;

private:
    size_t maxFiles;
    std::vector<FileInfo> files;
    std::map<fs::path, uintmax_t> directorySizes;
    std::map<std::string, std::pair<size_t, uintmax_t>> fileTypeSizes;

    void processFile(const fs::directory_entry& entry);
};

#endif // SCANNER_H
