#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
};

int height(Node* root) {
    if (root == NULL) return 0;
    int lD = height(root->left);
    int rD = height(root->right);
    if (lD > rD) return lD + 1;
    return rD + 1;
}

bool validateAVL(Node* root) {
    if (root == NULL) return true;
    if (abs(height(root->left) - height(root->right)) <= 1 && validateAVL(root->left) && validateAVL(root->right)) return true;
    return false;
}

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node* root = newNode(13);

    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(6);
    root->left->right = newNode(11);

    root->right = newNode(15);
    root->right->left = newNode(14);
    root->right->right = newNode(16);

    if (validateAVL(root)) {
        cout << "AVL Tree is Valid";
    } else {
        cout << "AVL Tree is Invalid";
    }

    cout << endl;

    return 0;
}
