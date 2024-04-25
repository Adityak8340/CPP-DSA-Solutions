#include <iostream>
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node; // Duplicate keys are not allowed in AVL tree
    }

    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

    int balanceFactor = getBalanceFactor(node);

    // Left Left Case
    if (balanceFactor > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balanceFactor < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balanceFactor > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balanceFactor < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rotateRight(root);
    }

    // Left Right Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    }

    // Right Left Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Insert elements into AVL tree
    int elements[] = {13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18};
    int numElements = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < numElements; i++) {
        root = insert(root, elements[i]);
    }

    std::cout << "Inorder traversal of AVL tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Delete an element from AVL tree
    int elementToDelete = 10;
    root = deleteNode(root, elementToDelete);

    std::cout << "Inorder traversal after deleting " << elementToDelete << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Search for a key element in AVL tree
    int key = 7;
    Node* result = search(root, key);

    if (result != nullptr) {
        std::cout << key << " found in AVL tree." << std::endl;
    } else {
        std::cout << key << " not found in AVL tree." << std::endl;
    }

    return 0;
}

// Inorder traversal of AVL tree: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 18 
// Inorder traversal after deleting 10: 1 2 3 4 5 6 7 8 9 11 12 13 14 18 
// 7 found in AVL tree.
