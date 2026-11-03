#include <iostream>
using namespace std;

struct FolderNode {
    int id;
    FolderNode* left;
    FolderNode* right;

    FolderNode(int val) {
        id = val;
        left = nullptr;
        right = nullptr;
    }
};

void preorderTraversal(FolderNode* root) {
    if (root == nullptr) return;
    
    cout << root->id << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    FolderNode* root = new FolderNode(15);
    root->left = new FolderNode(8);
    root->right = new FolderNode(25);
    
    root->left->left = new FolderNode(4);
    root->left->right = new FolderNode(12);
    
    root->right->right = new FolderNode(30);
    cout << "Folders in Preorder (Root-Left-Right): ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
