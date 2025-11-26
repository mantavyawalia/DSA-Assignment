#include <iostream>
#include <limits>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

bool isBST(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->key <= minVal || root->key >= maxVal)
        return false;

    return isBST(root->left, minVal, root->key) &&
           isBST(root->right, root->key, maxVal);
}

int main() {
    // Simple tree example
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "YES, it is a BST";
    else
        cout << "NO, it is NOT a BST";

    return 0;
}
