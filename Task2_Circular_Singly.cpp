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

class CircularList {
public:
    Node* head;

    CircularList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertPosition(int value, int position) {
        if (position == 1) {
            insertBeginning(value);
            return;
        }

        if (head == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;

            if (temp == head) {
                cout << "Invalid position" << endl;
                return;
            }
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == value) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            Node* del = head;
            head = head->next;
            temp->next = head;

            delete del;
            return;
        }

        Node* temp = head;

        while (temp->next != head && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next != head && temp->next->data == value) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        } else {
            cout << "Node not found" << endl;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main() {
    CircularList list;

    int choice;
    int value;
    int position;

    do {
        cout << "\n1. Insert at End";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Insert at Position";
        cout << "\n4. Delete Node";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
        } else if (choice == 3) {
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            list.insertPosition(value, position);
        } else if (choice == 4) {
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
        } else if (choice == 5) {
            list.display();
        }

    } while (choice != 6);

    return 0;
}
