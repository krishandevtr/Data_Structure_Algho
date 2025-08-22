#include <iostream>
#include <queue>
#include <stdexcept>
#include <algorithm> // For std::max

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BstADT
{
private:
    Node *root;

    // Insert helper
    Node* insert_helper(Node* node, int value);

    // Clear helper
    void clear_helper(Node* node);

    // Traversal helpers
    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    void levelOrder(Node* node);

    // Remove helper
    Node* remove_helper(Node* node, int value);

    // Count nodes helper
    int countNodes_helper(Node* node);

    // Height helper
    int height_helper(Node* node);

public:
    BstADT() : root(nullptr) {}
    ~BstADT() { clear(); }

    // Public methods
    void insert(int value);
    bool search(int value);
    int findMin();
    int findMax();
    int height();
    int countNodes();
    bool isEmpty();
    void clear();

    void inOrder();
    void preOrder();
    void postOrder();
    void levelOrder();

    void remove(int value);
    void remove_iterative(int value);
};

// ----------------- Implementation -----------------

Node* BstADT::insert_helper(Node* node, int value)
{
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert_helper(node->left, value);
    else if (value > node->data)
        node->right = insert_helper(node->right, value);

    return node;
}

void BstADT::insert(int value)
{
    root = insert_helper(root, value);
}

// ---------------------------------
void BstADT::clear_helper(Node* node)
{
    if (!node) return;
    clear_helper(node->left);
    clear_helper(node->right);
    delete node;
}

void BstADT::clear()
{
    clear_helper(root);
    root = nullptr;
}

// ---------------------------------
void BstADT::inOrder(Node* node)
{
    if (!node) return;
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

void BstADT::inOrder()
{
    inOrder(root);
    std::cout << "\n";
}

void BstADT::preOrder(Node* node)
{
    if (!node) return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BstADT::preOrder()
{
    preOrder(root);
    std::cout << "\n";
}

void BstADT::postOrder(Node* node)
{
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

void BstADT::postOrder()
{
    postOrder(root);
    std::cout << "\n";
}

void BstADT::levelOrder(Node* node)
{
    if (!node) return;
    std::queue<Node*> q;
    q.push(node);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        std::cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void BstADT::levelOrder()
{
    levelOrder(root);
    std::cout << "\n";
}

// ---------------------------------
bool BstADT::search(int value)
{
    Node* current = root;
    while (current)
    {
        if (current->data == value) return true;
        current = (value < current->data) ? current->left : current->right;
    }
    return false;
}

// ---------------------------------
int BstADT::findMin()
{
    if (!root) throw std::runtime_error("Tree is empty");
    Node* current = root;
    while (current->left) current = current->left;
    return current->data;
}

int BstADT::findMax()
{
    if (!root) throw std::runtime_error("Tree is empty");
    Node* current = root;
    while (current->right) current = current->right;
    return current->data;
}

// ---------------------------------
int BstADT::height_helper(Node* node)
{
    if (!node) return 0;
    return 1 + std::max(height_helper(node->left), height_helper(node->right));
}

int BstADT::height()
{
    return height_helper(root);
}

// ---------------------------------
int BstADT::countNodes_helper(Node* node)
{
    if (!node) return 0;
    return 1 + countNodes_helper(node->left) + countNodes_helper(node->right);
}

int BstADT::countNodes()
{
    return countNodes_helper(root);
}

// ---------------------------------
bool BstADT::isEmpty()
{
    return root == nullptr;
}

// ---------------------------------
Node* BstADT::remove_helper(Node* node, int value)
{
    if (!node) return nullptr;

    if (value < node->data)
        node->left = remove_helper(node->left, value);
    else if (value > node->data)
        node->right = remove_helper(node->right, value);
    else
    {
        // No child
        if (!node->left && !node->right)
        {
            delete node;
            return nullptr;
        }
        // One child
        if (!node->left)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Two children
        Node* successor = node->right;
        while (successor->left) successor = successor->left;
        node->data = successor->data;
        node->right = remove_helper(node->right, successor->data);
    }
    return node;
}

void BstADT::remove(int value)
{
    root = remove_helper(root, value);
}

// ---------------------------------
// Iterative remove stays same
void BstADT::remove_iterative(int value)
{
    Node* current = root;
    Node* parent = nullptr;

    while (current && current->data != value)
    {
        parent = current;
        if (value < current->data) current = current->left;
        else current = current->right;
    }

    if (!current) return;

    // Two children
    if (current->left && current->right)
    {
        Node* succParent = current;
        Node* succ = current->right;
        while (succ->left)
        {
            succParent = succ;
            succ = succ->left;
        }
        current->data = succ->data;
        current = succ;
        parent = succParent;
    }

    // One or no child
    Node* child = (current->left) ? current->left : current->right;
    if (!parent) root = child;
    else if (parent->left == current) parent->left = child;
    else parent->right = child;

    delete current;
}
