#include <iostream>
#include <climits> // For INT_MIN

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* top; // points to the top node of the stack
    int size;      // max size of stack
    int count;     // current number of elements

public:
    Stack(int size) : top(nullptr), size(size), count(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int el) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return;
        }
        Node* newNode = new Node(el);
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return INT_MIN;
        }
        Node* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        count--;
        return val;
    }

    int peek(int index) {
        if (index <= 0 || index > count) {
            std::cout << "Index Out of Bound\n";
            return INT_MIN;
        }
        Node* current = top;
        // index 1 means top element, so move index-1 times down
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return count == size;
    }
};

int main() {
    Stack st(3); // max size 3

    std::cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << "\n";

    // Test popping from empty stack
    std::cout << "Pop from empty stack: " << st.pop() << " (expect INT_MIN and error message)\n";

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    std::cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << "\n";

    // Try pushing when full
    st.push(40); // Should print overflow error

    // Peek tests
    std::cout << "Peek index 1 (top): " << st.peek(1) << " (expect 30)\n";
    std::cout << "Peek index 2: " << st.peek(2) << " (expect 20)\n";
    std::cout << "Peek index 3: " << st.peek(3) << " (expect 10)\n";
    std::cout << "Peek index 4 (out of bounds): " << st.peek(4) << " (expect INT_MIN and error message)\n";

    // Pop elements
    std::cout << "Pop: " << st.pop() << " (expect 30)\n";
    std::cout << "Pop: " << st.pop() << " (expect 20)\n";

    // Check empty/full status again
    std::cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << "\n";

    st.push(40);
    std::cout << "Peek index 1: " << st.peek(1) << " (expect 40)\n";

    std::cout << "Pop: " << st.pop() << " (expect 40)\n";
    std::cout << "Pop: " << st.pop() << " (expect 10)\n";

    std::cout << "Is stack empty after all pops? " << (st.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
