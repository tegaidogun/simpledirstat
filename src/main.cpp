#include "scanner.h"
#include "visualizer.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return 1;
    }
    fs::path directory_path = argv[1];
    if (!fs::exists(directory_path) || !fs::is_directory(directory_path)) {
        std::cerr << "Provided path does not exist or is not a directory." << std::endl;
        return 1;
    }

    auto files = scan_directory(directory_path);
    display_directory(files);

    return 0;
}
