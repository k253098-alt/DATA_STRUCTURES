
#include<iostream>
#include<string>
using namespace std;

class Parcel {
  public: 
    int trackingNo;
    string sender;
    string city;
    int region;
};

class Node {
public:	
    Parcel data;
    Node* next;

    Node(Parcel p) {
        data = p;
        next = NULL;
    }
};

void insert(Node*& head, Node*& tail, Parcel p) {
    Node* newNode = new Node(p);

    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void radixSort(Node*& head) {

    int exp = 1;

    for(int pass = 0; pass < 9; pass++) {

        Node* bucketHead[10] = {NULL};
        Node* bucketTail[10] = {NULL};

        Node* curr = head;

        while(curr != NULL) {

            Node* nextNode = curr->next;
            curr->next = NULL;

            int digit = (curr->data.trackingNo / exp) % 10;

            if(bucketHead[digit] == NULL) {
                bucketHead[digit] = curr;
                bucketTail[digit] = curr;
            }
            else {
                bucketTail[digit]->next = curr;
                bucketTail[digit] = curr;
            }

            curr = nextNode;
        }

        head = NULL;
        Node* tail = NULL;

        for(int i = 0; i < 10; i++) {

            if(bucketHead[i] != NULL) {

                if(head == NULL) {
                    head = bucketHead[i];
                    tail = bucketTail[i];
                }
                else {
                    tail->next = bucketHead[i];
                    tail = bucketTail[i];
                }
            }
        }

        exp *= 10;
    }
}

Node* merge(Node* left, Node* right) {

    Parcel p;
    Node dummy(p);

    Node* tail = &dummy;

    while(left != NULL && right != NULL) {

        if(left->data.region <= right->data.region) {
            tail->next = left;
            left = left->next;
        }
        else {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if(left != NULL) {
        tail->next = left;
    }
    else {
        tail->next = right;
    }

    return dummy.next;
}

Node* mergeSort(Node* head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* right = slow->next;
    slow->next = NULL;

    Node* left = mergeSort(head);
    right = mergeSort(right);

    return merge(left, right);
}

void display(Node* head) {

    int count = 0;

    while(head != NULL && count < 20) {

        cout << head->data.trackingNo << "\t\t"
             << head->data.sender << "\t"
             << head->data.city << "\t"
             << head->data.region << endl;

        head = head->next;
        count++;
    }

    if(count == 20) {
        cout << "Showing first 20 records only.\n";
    }
}

int main() {

    int n;

    cout << "Enter number of parcels: ";
    cin >> n;

    Node* trackingHead = NULL;
    Node* trackingTail = NULL;

    Node* regionHead = NULL;
    Node* regionTail = NULL;

    for(int i = 0; i < n; i++) {

        Parcel p;

        cout << "\nEnter tracking number: ";
        cin >> p.trackingNo;

        cout << "Enter sender name: ";
        cin >> p.sender;

        cout << "Enter destination city: ";
        cin >> p.city;

        cout << "Enter region code: ";
        cin >> p.region;

        insert(trackingHead, trackingTail, p);
        insert(regionHead, regionTail, p);
    }

    radixSort(trackingHead);

    cout << "\n--- TRACKING NUMBER SORTING ---\n";
    cout << "Tracking\tSender\tCity\tRegion\n";

    display(trackingHead);
    

    regionHead = mergeSort(regionHead);

    cout << "\n---REGION CODE SORTING ---\n";
    cout << "Tracking\tSender\tCity\tRegion\n";

    display(regionHead);

    return 0;
}
