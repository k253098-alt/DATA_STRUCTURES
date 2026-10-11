
#include <iostream>
using namespace std;

const int SIZE = 6;

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (count == SIZE)
            return;

        if (count == 0)
            front = 0;

        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (count == 0)
            return -1;

        int x = arr[front];
        front = (front + 1) % SIZE;
        count--;

        if (count == 0) {
            front = -1;
            rear = -1;
        }

        return x;
    }

    void display() {
        cout << "Final passengers: ";

        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % SIZE] << " ";

        cout << endl;
        cout << "Front position: " << front << endl;
        cout << "Rear position: " << rear << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    q.dequeue();
    q.dequeue();

    q.enqueue(110);

    q.dequeue();

    q.enqueue(111);
    q.enqueue(112);

    q.display();

    return 0;
}
