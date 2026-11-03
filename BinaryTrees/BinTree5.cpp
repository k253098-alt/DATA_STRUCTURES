#include <iostream>
using namespace std;

class Node{
public:	
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = right = nullptr;
	}
};

Node* createNode(int val){
	Node* newNode = new Node(val);
	return newNode;
}

int main(){
	Node* root = createNode(10);
	
	root->left = createNode(20);
	root->right = createNode(30);
	
	root->left->left = createNode(40);
	root->left->right = createNode(50);
	
	cout<<root->data <<endl;
	cout<<root->left->data <<endl;
	cout<<root->right->data <<endl;
	cout<<root->left->left->data <<endl;
	cout<<root->left->right->data <<endl;
}