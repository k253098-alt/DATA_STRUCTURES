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

void printPreorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostorder(Node* root) {
    if (root == nullptr) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    cout<<"\nPre Order\n";
    printPreorder(root);
    cout<<"\nPost Order\n";

    printPostorder(root);
    cout<<"\nIn Order\n";

	printInorder(root);
	

    return 0;
}
