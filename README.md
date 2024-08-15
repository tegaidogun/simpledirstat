# simpledirstat

**simpledirstat** is a command-line utility that provides a visual representation of disk usage on Linux systems, inspired by tools like WinDirStat and K4DirStat. It allows users to quickly understand how disk space is distributed across files and directories.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Make sure you have a C++ compiler and make installed on your system. This project also requires a C++17 standard compatible compiler due to its usage of the filesystem library.

### Installing

1. Clone the repository:
    ``` bash
   git clone https://github.com/tegaidogun/simpledirstat.git
   cd simpledirstat
   ```

2. Build the project:
   ``` bash
   make
   ```

3. Run the application:
   ``` bash
   ./simpledirstat /path/to/directory
   ```

## Usage

To use **simpledirstat**, simply run the executable followed by the path to the directory you want to analyze. For example:
./simpledirstat /home/user

## Project Goals

For a detailed overview of the project goals and what we aim to achieve with **simpledirstat**, please refer to [our goals](docs/GOALS.md) in the docs directory.

## Contributing

Contributions are welcome! For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

This project is licensed under the GNU GPL v3 License - see the LICENSE.md file for details.
