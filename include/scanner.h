#ifndef SCANNER_H
#define SCANNER_H

#include "common.h"

// Function to scan a directory and return file information
std::vector<FileInfo> scan_directory(const fs::path& directory);

#endif // SCANNER_H
