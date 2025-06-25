#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Dir {
private:
    string name;
    unique_ptr<Dir> sub_folder;
    unique_ptr<Dir> sibling;

public:
    Dir(string name) : name(name) {}

    void add_dir(const vector<string>& path, int index = 0) {
        if (index >= path.size()) return;

        string dir_name = path[index];
        Dir* current = this;

        Dir* child = sub_folder.get();
        Dir* prev = nullptr;

        while (child && child->name != dir_name) {
            prev = child;
            child = child->sibling.get();
        }

        if (!child) {
            unique_ptr<Dir> new_dir = make_unique<Dir>(dir_name);
            if (!prev) {
                sub_folder = move(new_dir);
                child = sub_folder.get();
            } else {
                prev->sibling = move(new_dir);
                child = prev->sibling.get();
            }
        }

        child->add_dir(path, index + 1);
    }

    Dir* search(const vector<string>& path, int index = 0) {
        if (index >= path.size()) return this;

        Dir* child = sub_folder.get();
        while (child) {
            if (child->name == path[index])
                return child->search(path, index + 1);
            child = child->sibling.get();
        }
        return nullptr;
    }

    bool delete_dir(const vector<string>& path, int index = 0) {
    if (index >= path.size()) return false;

    unique_ptr<Dir>* current = &sub_folder;

    while (*current) {
        if ((*current)->name == path[index]) {
            if (index == path.size() - 1) {
                // Found the directory to delete
                (*current) = move((*current)->sibling); // Remove and preserve siblings
                return true;
            } else {
                return (*current)->delete_dir(path, index + 1);
            }
        }
        current = &((*current)->sibling); // Move to next sibling
    }

    return false; // Not found
}

    void print_structure(int level = 0) const {
        for (int i = 0; i < level; ++i) cout << "  ";
        cout << name << endl;

        if (sub_folder) sub_folder->print_structure(level + 1);
        if (sibling) sibling->print_structure(level);
    }

    string get_name() const { return name; }
};

int main() {
    unique_ptr<Dir> root = make_unique<Dir>("root");

    root->add_dir({"folder1", "folder2"});
    root->add_dir({"folder1", "folder4"});
    root->add_dir({"folder1", "folder2", "folder5"});

    cout << "Initial structure:\n";
    root->print_structure();

    vector<string> search_path = {"folder1", "folder2","folder6"};
    cout << "\nSearching for: " << search_path.back() << endl;
    Dir* found = root->search(search_path);
    if (found)
        cout << search_path.back() << " Found directory: " << found->get_name() << endl;
    else
        cout << search_path.back() << " not found.\n";

    root->delete_dir({"folder1", "folder2"});

    cout << "\nAfter deleting folder1/folder2:\n";
    root->print_structure();

    return 0;
}
// This code implements a simple directory structure using a tree-like model with unique pointers.
// It allows adding, searching, and deleting directories while maintaining memory safety with smart pointers.