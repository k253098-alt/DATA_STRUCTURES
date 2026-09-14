#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = NULL;
			
		}
};

int main(){
	Node* head = new Node(4);
	Node* temp = new Node(20);
	temp->next = head;
	head = temp;
	
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next; 
	}
}