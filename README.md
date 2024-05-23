# Directory Tree Structure Generator

This C++ program generates a tree structure of a folder and its subfolders using ASCII characters. It recursively traverses the directory structure and prints each directory and file along with its indentation level.

## Usage

1. Compile the program using a C++ compiler with C++17 support (e.g., g++).
   ```
   g++ -std=c++17 gen.cpp -o gen
   ```

2. Run the compiled program.
   ```
   ./gen
   ```

3. Enter the path of the folder you want to generate the tree structure for when prompted.

4. Choose whether to expand every folder or not by entering "yes" or "no" when prompted.

5. The program will generate and print the tree structure of the specified folder.

## Dependencies

- C++17 standard library
- `<filesystem>` header (available in C++17)
