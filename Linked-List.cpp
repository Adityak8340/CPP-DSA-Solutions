#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Q1: Computes and returns the sum of all the integers between "first" and "last" inclusive.
int SumBetween(int first, int last) {
    int firstSum = (first * (first + 1) / 2);
    int secondSum = (last * (last + 1) / 2);
    int sum = secondSum - firstSum;
    return sum;
}

// Q2: Computes and returns the smallest positive integer n for which 1+2+3+...+n equals or exceeds the value of "goal".
int findSmallestN(int goal) {
    int n = 1; // Start with the first positive integer
    int sum = 0;
    while (sum < goal) {
        sum += n;
        n++;
    }
    return n - 1; // the smallest n for which the sum exceeds or equals the goal
}

// Q3: Computes and returns the greatest common divisor (g.c.d.) of the arguments passed to it.
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Q4: Determines whether an integer is prime.
bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Q5: Prints the English name of an integer from 1 to 9.
void printNumberInEnglish(int num) {
    switch (num) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
        case 6:
            cout << "Six";
            break;
        case 7:
            cout << "Seven";
            break;
        case 8:
            cout << "Eight";
            break;
        case 9:
            cout << "Nine";
            break;
        default:
            cout << "Number out of range (1-9)";
    }
}

// Q6: Finds the index of the largest number in an array.
int largestNumberIndex(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            return i;
        }
    }
    return 0;
}

// Q7: Reverses the order of the objects in an array.
// Q8: Examines an array of integers and eliminates all duplication of values. The distinct integers are all moved to the left part of the array.
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int writeIndex = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[writeIndex - 1]) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }
    return writeIndex;
}

// Q9: Copies numbers from two arrays into a third array. The numbers from the second array are placed to the right of the numbers copied from the first array.
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    // Copy elements from arr1 to arr3
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }
    // Copy elements from arr2 to arr3
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

// Q10: Program for adding and subtracting Matrices using 2D Arrays.
int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    int matrix1[rows][cols], matrix2[rows][cols], result_sum[rows][cols], result_diff[rows][cols];
    cout << "Enter elements of matrix 1:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix1[i][j];
        }
    }
    cout << "Enter elements of matrix 2:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix2[i][j];
        }
    }
    // Perform addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result_sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // Perform subtraction
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result_diff[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    // Print the results
    cout << "\nSum of matrices:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result_sum[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nDifference of matrices:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result_diff[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Q11: Multiply Matrices of nXn.
int main() {
    int n;
    cout << "Enter the size of the square matrices (nXn): ";
    cin >> n;
    int matrix1[n][n], matrix2[n][n], result[n][n];
    cout << "Enter elements of matrix 1:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }
    cout << "Enter elements of matrix 2:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix2[i][j];
        }
    }
    // Initialize result matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }
    // Perform matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    // Print the result matrix
    cout << "\nProduct of matrices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Q12: Create and display a circular LL
struct Node {
    int data;
    Node* next;
};
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to create a circular linked list with three nodes
Node* createCircularList() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    head->next = second;
    second->next = third;
    third->next = head; // Connect the last node back to the head
    return head;
}
// Function to display the circular linked list
void displayList(Node* head) {
    Node* current = head;
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head); // Stop when we reach the head again
    cout << endl;
}
int main() {
    Node* head = createCircularList();
    cout << "Circular linked list: ";
    displayList(head);
    return 0;
}

// Q13: Count and Sum the Nodes
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
int sumNodes(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// Q14: Search for a key element in a LL
bool searchKey(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Q15: Delete an Element
Node* deleteNode(Node* head, int key) {
    Node* current = head;
    Node* prev = nullptr;
    if (head != nullptr && head->data == key) {
        // Deleting head node
        head = head->next;
        delete current;
        return head;
    }
    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        return head; // Key not found
    }
    prev->next = current->next;
    delete current;
    return head;
}

// Q16: Check if Sorted
bool isSorted(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}

// Q17: Merge Two Linked Lists
Node* mergeLists(Node* head1, Node* head2) {
    Node* mergedHead = nullptr;
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeLists(head1, head2->next);
    }
    return mergedHead;
}

// Q18: Reverse the Elements
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Q19: Create a doubly LL, insert in a doubly LL, and reverse a doubly LL
// Structure for a doubly linked list node
struct NodeDoubly {
    int data;
    NodeDoubly* prev;
    NodeDoubly* next;
};
// Function to create a new doubly linked list node
NodeDoubly* createDoublyNode(int data) {
    NodeDoubly* newNode = new NodeDoubly();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}
// Function to insert a node at the beginning of a doubly linked list
void insertAtBeginning(NodeDoubly** head, int data) {
    NodeDoubly* newNode = createDoublyNode(data);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
// Function to reverse a doubly linked list
NodeDoubly* reverseDoubly(NodeDoubly* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    NodeDoubly* current = head;
    NodeDoubly* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (which is now the previous)
    }
    return temp->prev; // The new head is the previous tail
}

// Q20: Check odd occurrence of an element in an array.
bool hasOddOccurrences(int arr[], int n) {
    // Use a dictionary (map) to count occurrences
    unordered_map<int, int> occurrences;
    for (int i = 0; i < n; i++) {
        occurrences[arr[i]]++;
    }
    // Check for odd occurrences
    for (auto count : occurrences) {
        if (count.second % 2 != 0) {
            return true;
        }
    }
    return false;
}

// Q21 Given a matrix A. Write a program to find a sum of both diagonal elements of the matrix A.
int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    // Initialize a matrix based on user input
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    // Get matrix elements from the user
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }
    // Display the original matrix
    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // Calculate the sum of both diagonal elements
    int principalDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < rows; ++i) {
        principalDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][cols - 1 - i];
    }
    int diagonal = 0;
    if (rows % 2 == 1 && cols % 2 == 1) {
        diagonal = principalDiagonalSum + secondaryDiagonalSum - matrix[rows / 2][cols / 2];
    } else {
        diagonal = principalDiagonalSum + secondaryDiagonalSum;
    }
    // Display the sum of both diagonal elements
    cout << "\nSum of Principal Diagonal: " << principalDiagonalSum << endl;
    cout << "Sum of Secondary Diagonal: " << secondaryDiagonalSum << endl;
    cout << "Sum of Diagonal: " << diagonal << endl;
    return 0;
}
