#include <iostream>
#include <stdexcept>
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};


template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size_;

public:
    // Constructor
    LinkedList() : head(nullptr), size_(0) {}

    // Destructor to free all nodes
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

    // Appends a new node to the end of the list
    void append(const T& value) {
        Node<T>* new_node = new Node<T>(value);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
        size_++;
    }

    // Prepends a new node to the beginning of the list
    void prepend(const T& value) {
        Node<T>* new_node = new Node<T>(value);
        new_node->next = head;
        head = new_node;
        size_++;
    }
    
    // Removes the first occurrence of a value
    bool remove(const T& value) {
        if (head == nullptr) {
            return false;
        }
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size_--;
            return true;
        }
        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            size_--;
            return true;
        }
        return false;
    }

    // Accesses an element by index
    T& operator[](int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Checks if the list is empty
    bool is_empty() const {
        return head == nullptr;
    }

    // Returns the number of elements
    int size() const {
        return size_;
    }
};