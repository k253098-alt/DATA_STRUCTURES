#include <iostream>
using namespace std;

class Node{
public:	
	char data;
	Node* left;
	Node* right;
	
	Node(char val){
		data = val;
		left = right = nullptr;
	}
};

Node* createNode(char val){
	Node* newNode = new Node(val);
	return newNode;
}

void inOrder(Node* root){
	if(root == nullptr) return;
	
	if(root->left != nullptr) cout <<"(";
	inOrder(root->left);
	
	
		
	cout <<root->data << " ";
	inOrder(root->right);
	if(root->right != nullptr) cout<<")";
	
}

void postOrder(Node* root){
	if(root == nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
		
	cout <<root->data << " ";
}
 

void preOrder(Node* root){
	if(root == nullptr) return;
	
	cout <<root->data << " ";
	
	preOrder(root->left);
	preOrder(root->right);
		
	
}

int main(){
	Node* root = createNode('*');
	
	root->left = createNode('+');
	root->right = createNode('-');
	
	root->left->left = createNode('A');
	root->left->right = createNode('B');
	
	root->right->left = createNode('C');
	root->right->right = createNode('D');
	
	
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
	inOrder(root);
	return 0;
}