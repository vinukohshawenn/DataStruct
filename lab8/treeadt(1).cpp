#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree();
    void insert(int val);
    void search(int val);
    void display();
    void inorder();
    void preorder();
    void postorder();

private:
    Node* insert(Node* node, char val);
    Node* search(Node* node, char val);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    void display(Node* node);
};

// Main function with a menu-driven approach
int main() {
    Tree tree;
    int choice;
    char val;
    do {
        cout << "\nChoices (Tree Operations): \n";
        cout << "1. Insert an element\n";
        cout << "2. Search an element\n";
        cout << "3. Display Children\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the character: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Enter the character to search: ";
                cin >> val;
                tree.search(val);
                break;
            case 3:
                cout << "Displaying Children in the Binary Tree:\n";
                tree.display();
                break;
            case 4:
                cout << "Inorder Traversal:\n";
                tree.inorder();
                break;
            case 5:
                cout << "Preorder Traversal:\n";
                tree.preorder();
                break;
            case 6:
                cout << "Postorder Traversal:\n";
                tree.postorder();
                break;
            case 7:
                cout << "Exited the program.\n";
                break;
            default:
                cout << "INVALID!\n";
        }
    } while (choice != 7);
    return 0;
}

// Tree class function definitions

Tree::Tree() {
    root = nullptr;
}

void Tree::insert(char val) {
    root = insert(root, val);
}

Node* Tree::insert(Node* node, char val) {
    if (node == nullptr) {
        return new Node(val);
    }
    if (val < node->data) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    return node;
}

void Tree::search(char val) {
    Node* result = search(root, val);
    if (result)
        cout << "Element '" << val << "' found in the tree.\n";
    else
        cout << "Element '" << val << "' not found in the tree.\n";
}

Node* Tree::search(Node* node, char val) {
    if (node == nullptr || node->data == val) {
        return node;
    }
    if (val < node->data) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

void Tree::display() {
    if (root) {
        displayChildren(root);
    } else {
        cout << "Tree is empty.\n";
    }
}

void Tree::display(Node* node) {
    if (node) {
        cout << "Node: " << node->data << " -> ";
        if (node->left) cout << "Left: " << node->left->data << " ";
        if (node->right) cout << "Right: " << node->right->data;
        cout << endl;
        display(node->left);
        display(node->right);
    }
}

void Tree::inorder() {
    inorder(root);
    cout << endl;
}

void Tree::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void Tree::preorder() {
    preorder(root);
    cout << endl;
}

void Tree::preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void Tree::postorder() {
    postorder(root);
    cout << endl;
}

void Tree::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}
