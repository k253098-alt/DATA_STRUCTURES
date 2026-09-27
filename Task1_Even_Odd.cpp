#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void arrange() {
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* temp = head;

        while (temp != NULL) {
            Node* newNode = new Node(temp->data);

            if (temp->data % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = newNode;
                    evenTail = newNode;
                } else {
                    evenTail->next = newNode;
                    evenTail = newNode;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = newNode;
                    oddTail = newNode;
                } else {
                    oddTail->next = newNode;
                    oddTail = newNode;
                }
            }

            temp = temp->next;
        }

        if (evenHead == NULL) {
            head = oddHead;
        } else {
            head = evenHead;
            evenTail->next = oddHead;
        }
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insert(value);
    }

    cout << "Before: ";
    list.display();

    list.arrange();

    cout << "After: ";
    list.display();

    return 0;
}
