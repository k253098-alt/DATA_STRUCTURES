
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> incoming;
    stack<int> outgoing;

public:
    void enqueue(int x) {
        incoming.push(x);
    }

    int dequeue() {
        if (outgoing.empty()) {
            while (!incoming.empty()) {
                outgoing.push(incoming.top());
                incoming.pop();
            }
        }

        if (outgoing.empty())
            return -1;

        int x = outgoing.top();
        outgoing.pop();

        return x;
    }
};

int main() {
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');

    cout << char(q.dequeue()) << endl;

    q.enqueue('C');

    cout << char(q.dequeue()) << endl;
    cout << char(q.dequeue()) << endl;

    return 0;
}
