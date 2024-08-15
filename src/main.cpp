#include <algorithm>
#include "scanner.h"
#include "visualizer.h"

struct CommandLineOptions {
    fs::path directory;
    std::string sort_order = "size";  // Default sort by size

    static CommandLineOptions parse(int argc, char** argv) {
        CommandLineOptions options;
        if (argc < 2) {
            throw std::runtime_error("Usage: " + std::string(argv[0]) + " <directory_path> [--sort size|type]");
        }
        options.directory = argv[1];
        if (argc > 2 && std::string(argv[2]) == "--sort") {
            if (argc > 3 && (std::string(argv[3]) == "size" || std::string(argv[3]) == "type")) {
                options.sort_order = argv[3];
            } else {
                throw std::runtime_error("Invalid sort option. Use --sort size or type");
            }
        }
        return options;
    }
};

int main(int argc, char** argv) {
    try {
        auto options = CommandLineOptions::parse(argc, argv);

        if (!fs::exists(options.directory) || !fs::is_directory(options.directory)) {
            std::cerr << "Provided path does not exist or is not a directory." << std::endl;
            return 1;
        }

        auto files = scan_directory(options.directory);
        if (options.sort_order == "size") {
            std::sort(files.begin(), files.end(), [](const FileInfo& a, const FileInfo& b) {
                return a.size > b.size;  // Sort by size, descending
            });
        } else if (options.sort_order == "type") {
            std::sort(files.begin(), files.end(), [](const FileInfo& a, const FileInfo& b) {
                return a.path.extension() < b.path.extension();  // Sort by file type
            });
        }
        display_directory(files);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
