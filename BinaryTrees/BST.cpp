#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int value){
		data = value;
		left = right= nullptr;
	}
};

Node* insertNode(Node* root, int value){
	if(root == nullptr) return new Node(value);
	
    if(value < root->data){
    	root->left = insertNode(root->left, value);
	} else {
		root->right = insertNode(root->right, value);
	}
	
	return root;
	
}

void inOrder(Node* root){
	if(root == nullptr) return;
	
	inOrder(root->left);
	cout<<root->data <<" ";
	inOrder(root->right);
	
}

Node* buildTree(){
	Node* root = nullptr;
	int n, val;
	cout<<"Enter number of nodes: ";
	cin>>n;
	cout<<"ENter node values:"<<endl;
	for(int i=0; i<n;i++){
		cin>>val;
		root = insertNode(root, val);
	}
	
	return root;
}

Node* search(Node* root, int key){
	if(root == nullptr) return nullptr;
	
	if(root->data == key) return root;
	
	if(root->data > key) return search(root->left, key);
	if(root->data < key) return search(root->right, key);
} 

Node* inOrderSucc(Node* root){
	while(root->left != nullptr && root != nullptr){
		root = root->left;
	}
	
	return root;
}

int hight(Node* root){
	if(root==nullptr) return 0;
	
//	int x = hight(root->right);
//	int y = hight(root->left);
//	if(x>y){
//		return x+1;
//	} else {
//		return y+1;
//	}

    return max(hight(root->left), hight(root->right)) + 1;
}

int numOfNodes(Node* root){
	if(root==nullptr) return 0;
	
//	int x = hight(root->right);
//	int y = hight(root->left);
//	if(x>y){
//		return y+x+1;
//	}

    return hight(root->left) + hight(root->right) + 1;
}

Node* delNode(Node* root, int key){
	if(root == nullptr) return nullptr;
	
	if(key < root->data){
		root->left = delNode(root->left, key);
	} else if(key > root->data){
		root->right = delNode(root->right, key);
	} else {
		if(root->left == nullptr){
			Node* temp = root->right;
		    delete root;
		    return temp;
		}
		
		if(root->right == nullptr){
			Node* temp = root->left;
		    delete root;
		    return temp;
		}
		
		Node* inOsucc = inOrderSucc(root->right);
		root->data = inOsucc->data;
		root->right = delNode(root->right, inOsucc->data);
	}
	
	return root;
}

int main(){
	Node* root = buildTree();
	
	inOrder(root);
	cout<<endl;
	
	insertNode(root, 9);
	inOrder(root);
	cout<<endl;
	
	Node* found = search(root, 4);
	cout<<found->data;
	
	delNode(root, 6);
	inOrder(root);
	
	cout<<"Hight of the tree: ";
	int h = hight(root);
	cout<<"\n"<< h;
	
	int n = numOfNodes(root);
	cout<<"\n"<<n;
	return 0;
}