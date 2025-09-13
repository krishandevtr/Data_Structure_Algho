#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* leftChild;
    AVLNode* rightChild;
    // Height is to determine balance factor.
    int height;

    AVLNode(int value)
        : data(value), leftChild(nullptr), rightChild(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    // Utility functions
    int getHeight(AVLNode* node) const {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) const {
        return node ? getHeight(node->leftChild) - getHeight(node->rightChild) : 0;
    }

    void updateHeight(AVLNode* node) {
        node->height = 1 + max(getHeight(node->leftChild), getHeight(node->rightChild));
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->leftChild;
        AVLNode* T2 = x->rightChild;

        // Perform rotation
        x->rightChild = y;
        y->leftChild = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->rightChild;
        AVLNode* T2 = y->leftChild;

        // Perform rotation
        y->leftChild = x;
        x->rightChild = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Insert and balance
    AVLNode* insertNode(AVLNode* node, int value) {
        if (!node) return new AVLNode(value);

        if (value < node->data)
            node->leftChild = insertNode(node->leftChild, value);
        else if (value > node->data)
            node->rightChild = insertNode(node->rightChild, value);
        else
            return node; // No duplicates

        updateHeight(node);

        int balance = getBalance(node);

        // Balancing cases
        if (balance > 1 && value < node->leftChild->data)
            return rightRotate(node); // Left Left
        if (balance < -1 && value > node->rightChild->data)
            return leftRotate(node); // Right Right
        if (balance > 1 && value > node->leftChild->data) {
            node->leftChild = leftRotate(node->leftChild);
            return rightRotate(node); // Left Right
        }
        if (balance < -1 && value < node->rightChild->data) {
            node->rightChild = rightRotate(node->rightChild);
            return leftRotate(node); // Right Left
        }

        return node;
    }

    // Find min node (for deletion)
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->leftChild)
            current = current->leftChild;
        return current;
    }

    // Remove and balance
    AVLNode* removeNode(AVLNode* node, int value) {
        if (!node) return node;

        if (value < node->data)
            node->leftChild = removeNode(node->leftChild, value);
        else if (value > node->data)
            node->rightChild = removeNode(node->rightChild, value);
        else {
            // Node with one or no child
            if (!node->leftChild || !node->rightChild) {
                AVLNode* temp = node->leftChild ? node->leftChild : node->rightChild;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else
                    *node = *temp; // Copy contents
                delete temp;
            } else {
                AVLNode* temp = minValueNode(node->rightChild);
                node->data = temp->data;
                node->rightChild = removeNode(node->rightChild, temp->data);
            }
        }

        if (!node) return node;

        updateHeight(node);
        int balance = getBalance(node);

        // Balancing cases after deletion
        if (balance > 1 && getBalance(node->leftChild) >= 0)
            return rightRotate(node);
        if (balance > 1 && getBalance(node->leftChild) < 0) {
            node->leftChild = leftRotate(node->leftChild);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->rightChild) <= 0)
            return leftRotate(node);
        if (balance < -1 && getBalance(node->rightChild) > 0) {
            node->rightChild = rightRotate(node->rightChild);
            return leftRotate(node);
        }

        return node;
    }

    bool searchNode(AVLNode* node, int value) const {
        if (!node) return false;
        if (value == node->data) return true;
        if (value < node->data) return searchNode(node->leftChild, value);
        return searchNode(node->rightChild, value);
    }

    void inOrderTraversal(AVLNode* node) const {
        if (!node) return;
        inOrderTraversal(node->leftChild);
        cout << node->data << " ";
        inOrderTraversal(node->rightChild);
    }

    void preOrderTraversal(AVLNode* node) const {
        if (!node) return;
        cout << node->data << " ";
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
    }

    void postOrderTraversal(AVLNode* node) const {
        if (!node) return;
        postOrderTraversal(node->leftChild);
        postOrderTraversal(node->rightChild);
        cout << node->data << " ";
    }

    void clearTree(AVLNode* node) {
        if (!node) return;
        clearTree(node->leftChild);
        clearTree(node->rightChild);
        delete node;
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {
        clearTree(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = removeNode(root, value);
    }

    bool search(int value) const {
        return searchNode(root, value);
    }

    void inOrder() const {
        inOrderTraversal(root);
        cout << endl;
    }

    void preOrder() const {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrder() const {
        postOrderTraversal(root);
        cout << endl;
    }

    int height() const {
        return getHeight(root);
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    AVLNode* getRoot() const {
        return root;
    }
};
