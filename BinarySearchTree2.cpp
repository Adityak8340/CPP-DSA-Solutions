#include <iostream>
using namespace std;

// Definition of a BST node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a value into a BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Function to create a BST from an array of elements
TreeNode* createBST(int arr[], int n) {
    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Recursive function for BST search
bool searchRecursive(TreeNode* root, int val) {
    if (root == NULL) return false;
    if (root->val == val) return true;
    if (val < root->val) return searchRecursive(root->left, val);
    return searchRecursive(root->right, val);
}

// Iterative function for BST search
bool searchIterative(TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) return true;
        if (val < root->val) root = root->left;
        else root = root->right;
    }
    return false;
}

// Function to perform in-order traversal of BST
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Function to perform pre-order traversal of BST
void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to perform post-order traversal of BST
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (val < root->val) root->left = deleteNode(root->left, val);
    else if (val > root->val) root->right = deleteNode(root->right, val);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main() {
    int arr[] = {13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a BST
    TreeNode* root = createBST(arr, n);

    // Print in-order traversal
    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    // Print pre-order traversal
    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    // Print post-order traversal
    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    // Search for an element in BST
    int searchVal = 8;
    cout << "Search for " << searchVal << " (recursive): " << (searchRecursive(root, searchVal) ? "Found" : "Not found") << endl;
    cout << "Search for " << searchVal << " (iterative): " << (searchIterative(root, searchVal) ? "Found" : "Not found") << endl;

    // Delete a node from BST
    int deleteVal = 8;
    root = deleteNode(root, deleteVal);
    cout << "After deleting " << deleteVal << ", in-order traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
