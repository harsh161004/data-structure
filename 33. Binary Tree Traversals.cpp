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

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = newNode(100);
    root->left = newNode(20);
    root->right = newNode(200);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->left = newNode(150);
    root->right->right = newNode(300);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    return 0;
}
