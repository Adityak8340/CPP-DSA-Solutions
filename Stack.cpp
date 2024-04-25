#include <iostream>
using namespace std;

// Stack class using arrays
class Stack {
private:
    int size;
    int* a;
    int top1;
public:
    Stack(int capacity) {
        this->size = capacity;
        a = new int[size];
        top1 = -1;
    }
    void push(int num) {
        if (!isFull()) {
            top1++;
            a[top1] = num;
        }
        // Else: Stack is full, cannot push
    }
    int pop() {
        if (!isEmpty()) {
            int x = a[top1];
            top1--;
            return x;
        }
        // Else: Stack is empty, cannot pop
        return -1;
    }
    int top() {
        if (top1 == -1)
            return -1;
        return a[top1];
    }
    int isEmpty() {
        return top1 == -1;
    }
    int isFull() {
        return top1 == size - 1;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Assuming -1 represents an invalid value.
        }
        return a[top1];
    }
    int stackTop() {
        return top1;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;
    Stack myStack(capacity);

    // Pushing elements into the stack
    for (int i = 1; i <= capacity; i++) {
        myStack.push(i);
        cout << "Pushed: " << i << endl;
    }

    // Attempting to push when the stack is full
    myStack.push(99); // This should not be pushed as the stack is full

    // Checking if the stack is full
    if (myStack.isFull()) {
        cout << "Stack is full!" << endl;
    }

    cout << "Peek: " << myStack.peek() << endl;
    cout << "Stack Top: " << myStack.stackTop() << endl;

    // Popping elements from the stack
    while (!myStack.isEmpty()) {
        cout << "Popped: " << myStack.pop() << endl;
    }

    // Attempting to pop when the stack is empty
    int poppedValue = myStack.pop(); // This should return -1 as the stack is empty
    if (poppedValue == -1) {
        cout << "Stack is empty!" << endl;
    }

    return 0;
}
