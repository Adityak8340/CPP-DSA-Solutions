#include <iostream>
#include <stack>
#include <stdexcept>
#include <queue>
using namespace std;

// Question 1: Implementing a Queue using an Array
#define MAX_SIZE 5
class Queue {
private:
    int items[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        items[++rear] = element;
        cout << element << " enqueued successfully.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int removedItem = items[front++];
        if (front > rear) {
            front = rear = -1;
        }
        cout << removedItem << " dequeued successfully.\n";
        return removedItem;
    }
};

// Question 2: Implementing a Queue using Stacks
class QueueStack {
private:
    stack<int> forward;
    stack<int> reverse;

public:
    void enqueue(int element) {
        forward.push(element);
    }

    int dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty. Cannot dequeue.");
        }
        if (reverse.empty()) {
            while (!forward.empty()) {
                reverse.push(forward.top());
                forward.pop();
            }
        }
        int frontElement = reverse.top();
        reverse.pop();
        return frontElement;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return forward.empty() && reverse.empty();
    }
};

// Question 3: Implementing a Priority Queue using STL
class PriorityQueue {
private:
    priority_queue<int> pq;

public:
    void enqueue(int element) {
        pq.push(element);
    }

    int dequeue() {
        if (isEmpty()) {
            throw out_of_range("Priority queue is empty. Cannot dequeue.");
        }
        int frontElement = pq.top();
        pq.pop();
        return frontElement;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return pq.empty();
    }
};

// Main function for the menu-driven program
void menuDriven() {
    int choice, element;
    Queue queue;
    QueueStack queueStack;
    PriorityQueue priorityQueue;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue to Queue\n";
        cout << "2. Dequeue from Queue\n";
        cout << "3. Enqueue to Queue implemented using Stacks\n";
        cout << "4. Dequeue from Queue implemented using Stacks\n";
        cout << "5. Enqueue to Priority Queue\n";
        cout << "6. Dequeue from Priority Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue to Queue: ";
                cin >> element;
                queue.enqueue(element);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Enter element to enqueue to Queue implemented using Stacks: ";
                cin >> element;
                queueStack.enqueue(element);
                break;
            case 4:
                try {
                    element = queueStack.dequeue();
                    cout << element << " dequeued successfully.\n";
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 5:
                cout << "Enter element to enqueue to Priority Queue: ";
                cin >> element;
                priorityQueue.enqueue(element);
                break;
            case 6:
                try {
                    element = priorityQueue.dequeue();
                    cout << element << " dequeued successfully.\n";
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 7);
}

int main() {
    menuDriven();
    return 0;
}
