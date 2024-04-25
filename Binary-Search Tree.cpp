

#include <iostream>


//Q1 Define the structure for a BST node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

//Q3 Function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

//Q2 Function to create a BST from an array
TreeNode* createBSTFromArray(const int arr[], int n) {
    TreeNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = insert(root, arr[i]);
    }
    return root;
}

//Q4 In-order traversal of the BST (for testing)
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
//Q5(A)
// Iterative search function
bool searchIterative(TreeNode* root, int target) {
    while (root != nullptr) {
        if (root->data == target) {
            return true; // Value found
        } else if (target < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false; // Value not found
}
//Q5(B)
// Recursive search function
bool searchRecursive(TreeNode* root, int target) {
    if (root == nullptr) {
        return false; // Value not found
    }
    if (root->data == target) {
        return true; // Value found
    }
    if (target < root->data) {
        return searchRecursive(root->left, target);
    } else {
        return searchRecursive(root->right, target);
    }
}

int main() {
    int arr[] = {10, 5, 15, 3, 7, 12, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = createBSTFromArray(arr, n);

    std::cout << "In-order traversal of the BST: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    insert(root, 30);
    std::cout<<"After adding 30"<<std::endl;
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Searching recursively for node value 15.... FOUND: " << searchRecursive(root, 15) << std::endl;

    std::cout << "Searching iteratively for node value 13.... FOUND: " << searchIterative(root, 13) << std::endl;

    return 0;
}
