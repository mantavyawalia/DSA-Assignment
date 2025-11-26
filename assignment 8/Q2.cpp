#include <iostream>
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

Node* insertNode(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else root->right = insertNode(root->right, key);
    return root;
}

// (a) Search – Recursive
Node* searchRecursive(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Search – Iterative
Node* searchIterative(Node* root, int key) {
    while (root) {
        if (key == root->key) return root;
        else if (key < root->key) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

// (b) Maximum
Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

// (c) Minimum
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* target) {
    if (!target) return nullptr;

    if (target->right) return findMin(target->right);

    Node* succ = nullptr;
    while (root) {
        if (target->key < root->key) {
            succ = root;
            root = root->left;
        } else if (target->key > root->key) {
            root = root->right;
        } else break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    if (!target) return nullptr;

    if (target->left) return findMax(target->left);

    Node* pred = nullptr;
    while (root) {
        if (target->key > root->key) {
            pred = root;
            root = root->right;
        } else if (target->key < root->key) {
            root = root->left;
        } else break;
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 25);
    insertNode(root, 35);

    Node* x = searchIterative(root, 15);

    cout << "Max: " << findMax(root)->key << endl;
    cout << "Min: " << findMin(root)->key << endl;

    Node* succ = inorderSuccessor(root, x);
    if (succ) cout << "Successor of 15: " << succ->key << endl;

    Node* pred = inorderPredecessor(root, x);
    if (pred) cout << "Predecessor of 15: " << pred->key << endl;

    return 0;
}

