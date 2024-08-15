#include "common.h"

std::string format_size(uintmax_t size) {
    const std::vector<std::string> sizes = {"B", "KB", "MB", "GB", "TB"};
    int order = 0;
    double formattedSize = size;
    while (formattedSize >= 1024 && order < static_cast<int>(sizes.size()) - 1) {
        order++;
        formattedSize /= 1024;
    }
    return std::to_string(formattedSize) + ' ' + sizes[order];
}
