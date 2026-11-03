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


Node* buildTree(){
	int val;
	
	cout<<"Enter value (-1 for no Node): ";
	cin>>val;
	if(val == -1) return nullptr;
	
	Node* root = createNode(val);
	cout<< "Enter left child of " <<val << endl;
	root->left = buildTree(); 
	
	cout<< "Enter right child of " <<val << endl;
	root->right = buildTree();
	
	return root;
}

void display(Node* temp){
	if(temp == nullptr) return;
	
	if(temp->left == nullptr) return;
	
	cout<<"left node of " <<temp->data <<endl;
	cout<<temp->left->data << endl;
	
	display(temp->left);
	
	if(temp->right == nullptr) return;
	
	cout<<"right node of " <<temp->data <<endl;
	cout<<temp->right->data << endl;
	
	display(temp->right);
	
}

void inOrder(Node* root){
	if(root == nullptr) return;
	inOrder(root->left);
		
	cout <<root->data << " ";
	inOrder(root->right);
	
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
	Node* root = buildTree();
	
	cout<<"root value: " <<root->data <<endl;
	
	cout<<"~~~Display~~~\n";
	
    
    display(root);
    cout<<"\nPre Order\n";
    preOrder(root);
    cout<<"\nPost Order\n";

    postOrder(root);
    cout<<"\nIn Order\n";

	inOrder(root);
	return 0;
}