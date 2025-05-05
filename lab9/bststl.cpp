#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    void constructExpressionTree(const string& postfixExpression) {
        stack<TreeNode*> s;
        stringstream ss(postfixExpression);
        string token;

        while (ss >> token) {
            if (isdigit(token[0])) {
                s.push(new TreeNode(token));
            } else {
                TreeNode* node = new TreeNode(token);
                node->right = s.top();
                s.pop();
                node->left = s.top();
                s.pop();
                s.push(node);
            }
        }
        root = s.top();
    }

    void preorderTraversal(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }
};

string getPostfixExpression() {
    string expression;
    while (true) {
        cout << "Enter a valid postfix expression (space-separated): ";
        getline(cin, expression);

        stringstream ss(expression);
        string token;
        bool valid = true;
        while (ss >> token) {
            if (!isdigit(token[0]) && token != "+" && token != "-" && token != "*" && token != "/") {
                valid = false;
                break;
            }
        }
        if (valid) {
            return expression;
        } else {
            cout << "Invalid input. Please enter a valid postfix expression.\n";
        }
    }
}

int main() {
    BinaryTree tree;
    string postfixExpression;

    while (true) {
        cout << "\nOperations:\n";
        cout << "1. Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder\n";
        cout << "4. Inorder\n";
        cout << "5. Postorder\n";
        cout << "6. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume newline

        switch (choice) {
            case 1:
                postfixExpression = getPostfixExpression();
                break;
            case 2:
                if (!postfixExpression.empty()) {
                    tree.constructExpressionTree(postfixExpression);
                } else {
                    cout << "Please enter a postfix expression first.\n";
                }
                break;
            case 3:
                if (tree.root) {
                    cout << "Preorder Traversal: ";
                    tree.preorderTraversal(tree.root);
                    cout << endl;
                } else {
                    cout << "Tree is empty.\n";
                }
                break;
            case 4:
                if (tree.root) {
                    cout << "Inorder Traversal: ";
                    tree.inorderTraversal(tree.root);
                    cout << endl;
                } else {
                    cout << "Tree is empty.\n";
                }
                break;
            case 5:
                if (tree.root) {
                    cout << "Postorder Traversal: ";
                    tree.postorderTraversal(tree.root);
                    cout << endl;
                } else {
                    cout << "Tree is empty.\n";
                }
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}