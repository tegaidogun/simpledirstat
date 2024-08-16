#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "common.h"
#include <vector>
#include <map>

void displayDirectories(const std::map<fs::path, uintmax_t>& directorySizes, uintmax_t totalSize);
void displayFiles(const std::vector<FileInfo>& files);
void displayFileTypeSummary(const std::map<std::string, std::pair<size_t, uintmax_t>>& fileTypeSummary, size_t n);

#endif // VISUALIZER_H
