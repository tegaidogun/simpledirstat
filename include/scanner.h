#ifndef SCANNER_H
#define SCANNER_H

#include "common.h"

std::vector<FileInfo> scan_directory(const fs::path& directory);

#endif // SCANNER_H
