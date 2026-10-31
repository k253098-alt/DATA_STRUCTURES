#include <iostream>
#include <string>

using namespace std;

struct Job {
    string name;
    int priority;
    int arrivalOrder;
};

class PriorityQueue {
private:
    Job heap[100];
    int capacity;
    int size;
    int counter;

    bool isHigherPriority(const Job& a, const Job& b) {
        if (a.priority != b.priority) {
            return a.priority < b.priority;
        }
        return a.arrivalOrder < b.arrivalOrder;
    }

    void swapJobs(int i, int j) {
        Job temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (isHigherPriority(heap[index], heap[parent])) {
                swapJobs(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    void siftDown(int index) {
        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && isHigherPriority(heap[left], heap[smallest])) {
                smallest = left;
            }
            if (right < size && isHigherPriority(heap[right], heap[smallest])) {
                smallest = right;
            }

            if (smallest != index) {
                swapJobs(index, smallest);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue() {
        size = 0;
        capacity = 100;
        counter = 0;
    }

    void push(string jobName, int priority) {
        if (size >= capacity) {
            cout << "Queue Full!\n";
            return;
        }
        
        Job newJob;
        newJob.name = jobName;
        newJob.priority = priority;
        newJob.arrivalOrder = ++counter;

        heap[size] = newJob;
        siftUp(size);
        size++;
    }

    Job pop() {
        if (size == 0) {
            cout << "Queue Empty!\n";
            return {"", -1, -1};
        }

        Job minJob = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) {
            siftDown(0);
        }

        return minJob;
    }

    Job peek() {
        if (size == 0) {
            cout << "Queue Empty!\n";
            return {"", -1, -1};
        }
        return heap[0];
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;

    pq.push("J1", 3);
 
    pq.push("J2", 1);
 
    pq.push("J3", 2);
 
    cout << "Step 4 (POP): Printed " << pq.pop().name << endl;
 
    pq.push("J4", 1);
 
    pq.push("J5", 3);
 
    cout << "Step 7 (POP): Printed " << pq.pop().name << endl;
 
    cout << "Step 8 (POP): Printed " << pq.pop().name << endl;
 
    pq.push("J6", 2);
 
    cout << "Step 10 (POP): Printed " << pq.pop().name << endl;
    cout << "Step 11 (POP): Printed " << pq.pop().name << endl;
    cout << "Step 12 (POP): Printed " << pq.pop().name << endl;

    return 0;
}