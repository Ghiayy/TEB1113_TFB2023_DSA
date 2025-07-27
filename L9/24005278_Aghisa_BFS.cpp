#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a node following BST rules
    Node* insert(Node* current, string name) {
        if (current == nullptr) {
            return new Node(name);
        }

        if (name < current->name) {
            current->left = insert(current->left, name);
        } else if (name > current->name) {
            current->right = insert(current->right, name);
        }
        
        return current;
    }

    void insert(string name) {
        root = insert(root, name);
    }

    // Search in BST
    Node* search(Node* current, string target) {
        if (current == nullptr || current->name == target)
            return current;

        if (target < current->name)
            return search(current->left, target);
        else
            return search(current->right, target);
    }

    Node* search(string target) {
        return search(root, target);
    }

    // In-order traversal for debugging
    void in_order(Node* node) {
        if (node == nullptr) return;
        in_order(node->left);
        cout << node->name << " ";
        in_order(node->right);
    }

    void display() {
        cout << "\nIn-order traversal: ";
        in_order(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // Insert nodes (will be placed according to BST rules)
    tree.insert("D");
    tree.insert("B");
    tree.insert("F");
    tree.insert("A");
    tree.insert("C");
    tree.insert("E");
    tree.insert("G");

    tree.display();

    string searchName;
    cout << "\nEnter name to search: ";
    cin >> searchName;

    Node* result = tree.search(searchName);
    if (result != nullptr) {
        cout << "Node found: " << result->name << endl;
    } else {
        cout << "Node not found." << endl;
    }

    return 0;
}

