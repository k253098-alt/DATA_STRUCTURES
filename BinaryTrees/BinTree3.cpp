#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {

    Node* root = new Node(35);
    
    root->left = new Node(18);
    root->left->left = new Node(10);
    root->left->right = new Node(25);

    root->right = new Node(55);
    root->right->left = new Node(45);
    root->right->right = new Node(65);
    cout << "Inorder Traversal (Left-Root-Right): " <<endl;
    inorderTraversal(root);
    cout << endl;
    return 0;
}
