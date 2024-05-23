#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

vector<string> tree_structure;

void recurse(const fs::path& folder, bool expand_all, const string& indent = "", int level = 0) {
    vector<fs::directory_entry> items;
    for (const auto& entry : fs::directory_iterator(folder)) {
        items.push_back(entry);
    }
    sort(items.begin(), items.end(), [](const fs::directory_entry& a, const fs::directory_entry& b) {
        return a.path().filename().string() < b.path().filename().string();
    });
    for (size_t i = 0; i < items.size(); i++) {
        const auto& item = items[i];
        const auto& path = item.path();
        bool is_last = i == items.size() - 1;
        tree_structure.push_back(indent + (is_last ? "└── " : "├── ") + path.filename().string());
        if (fs::is_directory(path) && (level == 0 || expand_all)) {
            string new_indent = indent + (is_last ? "    " : "│   ");
            recurse(path, expand_all, new_indent, level + 1);
        }
    }
}

void create_tree_structure(const fs::path& root_folder, bool expand_all) {
    recurse(root_folder, expand_all);
}

int main() {
    string folder_path;
    cout << "Enter the path of the folder: ";
    cin >> folder_path;
    
    if (!fs::is_directory(folder_path)) {
        cout << "The provided path is not a directory or does not exist." << endl;
        return 1;
    }

    string expand_all_input;
    cout << "Do you want to expand every folder? (yes/no): ";
    cin >> expand_all_input;
    bool expand_all = expand_all_input == "yes";

    create_tree_structure(folder_path, expand_all);

    for (const auto& line : tree_structure) {
        cout << line << endl;
    }
}
