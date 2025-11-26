#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int key) {
    Node* temp = new Node();
    temp->key = key;
    temp->left = temp->right = nullptr;
    return temp;
}

// (a) Insert element (no duplicates)
Node* insertNode(Node* root, int key) {
    if (!root) return newNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    // duplicates not allowed → ignore
    return root;
}

// Find minimum value node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// (b) Delete an existing element
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (!root->left && !root->right) { // No child
            delete root;
            return nullptr;
        }
        else if (!root->left) { // Only right child
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) { // Only left child
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// (c) Maximum depth of BST
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// (d) Minimum depth of BST
int minDepth(Node* root) {
    if (!root) return 0;
    
    if (!root->left && !root->right)
        return 1;

    if (!root->left)
        return 1 + minDepth(root->right);

    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Sample insertions
    root = insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 25);
    insertNode(root, 35);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // Delete example
    root = deleteNode(root, 10);
    cout << "After deleting 10: ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
