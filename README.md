# SimpleDirStat

SimpleDirStat is a command-line utility designed to analyze and display directory and file statistics based on their sizes. It offers a simple yet powerful way to visualize file system usage, making it easy to identify large files and directories quickly.

## NOTE
It's only been tested to work on Linux

## Features

- **Default Display:** Shows first-level directories with their sizes relative to the entire directory's size.
- **--filetype [n]:** Displays the largest 'n' files sorted by file size within their file types. If 'n' is not specified, it displays all file types.
- **--filesize [n]:** Displays the largest 'n' files across all directories. If 'n' is not specified, it shows all files sorted by size.

## Usage

To use SimpleDirStat, navigate to your project directory and run one of the following commands depending on what information you need:

```bash 
simpledirstat [directory]
```
This will display the size of each first-level directory within the specified directory relative to its total size.

```bash
simpledirstat [directory] --filetype [n]
```
This command will list the 'n' largest files sorted by file size within each file type. If 'n' is omitted, all file types are displayed.

```bash 
simpledirstat [directory] --filesize [n]
```
This displays the 'n' largest files across all directories. If 'n' is not provided, it lists all files sorted by size.

## Installation

1. Clone the repository to your local machine.
2. Navigate to the cloned directory.
3. Run make to build the project.
4. Navigate to the build folder inside the project to find the executable.

## Example

To analyze the directory ~/Documents, you can run:

```bash
simpledirstat ~/Documents
```

To display file types in the directory ~/Documents:

```bash 
simpledirstat ~/Documents --filetype
```

## Licensing

This project is licensed under the GNU General Public License v3.0.

## Contributing

Contributions to SimpleDirStat are welcome. Please fork the repository, make your changes, and submit a pull request.
