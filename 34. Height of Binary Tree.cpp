#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Node* root) {
    if (root == NULL) return 0;
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
}

int main() {
    Node* root = newNode(100);
    root->left = newNode(20);
    root->right = newNode(200);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->left = newNode(150);
    root->right->right = newNode(300);

    cout << "Height of Binary Tree is " << height(root) << endl;

    return 0;
}
