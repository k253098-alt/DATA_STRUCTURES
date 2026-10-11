
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

using Queue = queue<string>;

void reverseFirstK(Queue &q, int k) {
    if (k <= 0 || k > q.size())
        return;

    stack<string> s;
    int n = q.size();

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    Queue q;

    q.push("J1");
    q.push("J2");
    q.push("J3");
    q.push("J4");
    q.push("J5");
    q.push("J6");
    q.push("J7");

    reverseFirstK(q, 3);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    return 0;
}
