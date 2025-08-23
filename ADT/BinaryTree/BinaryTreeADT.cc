#include <queue>
#include <iostream>
using namespace std;

struct Node {
    Node* leftChild;
    Node* rightChild;
    int data;

    Node(int value) : data(value), leftChild(nullptr), rightChild(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void clear(Node* node);
    int countNodes(Node* node) const;
    int treeHeight(Node* node) const;
    int countLeafs(Node* node) const;

public:
     BinaryTree();
    ~BinaryTree();

    void insert(const int value);
    void postOrder(Node* node);
    void preOrder(Node* node) const;
    void inOrder(Node* node) const;
    void levelOrder(Node* node) const;

    void count() const;
    void height() const;
    void numberOfLeafs() const;

    Node* getRoot();
};



BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    clear(this->root);
}

void BinaryTree::clear(Node* node) {
    if (!node) return;
    clear(node->leftChild);
    clear(node->rightChild);
    delete node;
}

int BinaryTree::countNodes(Node* node) const {
    if (!node) return 0;
    return 1 + countNodes(node->leftChild) + countNodes(node->rightChild);
}

int BinaryTree::treeHeight(Node* node) const {
    if (!node) return 0;
    int leftH = treeHeight(node->leftChild);
    int rightH = treeHeight(node->rightChild);
    return 1 + max(leftH, rightH);
}

int BinaryTree::countLeafs(Node* node) const {
    if (!node) return 0;
    if (!node->leftChild && !node->rightChild) return 1;
    return countLeafs(node->leftChild) + countLeafs(node->rightChild);
}

void BinaryTree::insert(const int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->leftChild == nullptr) {
            node->leftChild = new Node(value);
            return;
        } else {
            q.push(node->leftChild);
        }

        if (node->rightChild == nullptr) {
            node->rightChild = new Node(value);
            return;
        } else {
            q.push(node->rightChild);
        }
    }
}

void BinaryTree::postOrder(Node* node) {
    if (node == nullptr) return;
    postOrder(node->leftChild);
    postOrder(node->rightChild);
    cout << node->data << " ";
}

void BinaryTree::preOrder(Node* node) const {
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrder(node->leftChild);
    preOrder(node->rightChild);
}

void BinaryTree::inOrder(Node* node) const {
    if (!node) return;
    inOrder(node->leftChild);
    cout << node->data << " ";
    inOrder(node->rightChild);
}

void BinaryTree::levelOrder(Node* node) const {
    if (node == nullptr) return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";
        if (current->leftChild) q.push(current->leftChild);
        if (current->rightChild) q.push(current->rightChild);
    }
}

void BinaryTree::count() const {
    cout << "Total nodes: " << countNodes(root) << endl;
}

void BinaryTree::height() const {
    cout << "Tree height: " << treeHeight(root) << endl;
}

void BinaryTree::numberOfLeafs() const {
    cout << "Leaf nodes: " << countLeafs(root) << endl;
}

Node* BinaryTree::getRoot() {
    return root;
}
