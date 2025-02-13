# hexcat
hexcat (v1.0.0) is a command-line utility that allows users to view the contents of a file in hexadecimal format.

Features
- Display file contents in hexadecimal format.
- Flexible options for specifying byte ranges, start and end positions, and byte offsets.
- Supports both hexadecimal and decimal input for byte positions.
- Handles invalid combinations of options with clear error messages.

## Installation
For now there is no installer, but the program can be compiled and the executable generated.
```bash
git clone https://github.com/samuelSanchezDev/hexcat.git
cd hexcat
make
```
The file is generated in the folder `bin`

## Usage
To run the program, use the following command:
```bash
hexcat [OPTIONS] <file>
```
Where `<file>` is the path to the file you want to inspect.

### Options
- `-s, --start <byte>`. Specify the starting byte from which to begin displaying the file's contents. You can input the byte in hexadecimal or decimal format.
- `-e, --end <byte>`. Specify the byte where to stop displaying the file’s contents. The input format can be hexadecimal or decimal.
- `-r, --range <start>:<end>`. View a range of bytes from <start> to <end>. Both start and end can be specified in hexadecimal or decimal format.
- `-n, --num-bytes <count>`. Display <count> bytes starting from the <start> byte. The byte count starts at 0, so this option helps you specify an exact number of bytes to show.
- `-b, --byte-offset <byte>`. Start viewing the file from a specific byte offset (relative position).
- `-v, --version`. Display the current version of the program.
- `-h, --help`. Show the help message with a summary of available options and how to use the program.

### Examples
1. Display a specific byte range
    View the file's contents from byte 100 to byte 200 (in hexadecimal):
    ```bash
    hexcat --start 0x64 --end 0xc8 myfile.bin
    ```

2. Display a specific number of bytes
    Display the first 50 bytes from the file:
    ```bash
    hexcat --num-bytes 50 myfile.bin
    ```

3. View a range using --range
    View bytes from position 100 to position 200:
    ```bash
    hexcat --range 100:200 myfile.bin
    ```

4. View file with a byte offset
    Start viewing the file from byte offset 50:
    ```bash
    hexcat --byte-offset 50 myfile.bin
    ```
