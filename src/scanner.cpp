#include "scanner.h"

std::vector<FileInfo> scan_directory(const fs::path& directory) {
    std::vector<FileInfo> files;
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (fs::is_regular_file(entry)) {
            FileInfo info{entry.path(), fs::file_size(entry)};
            files.push_back(info);
        }
    }
    return files;
}
