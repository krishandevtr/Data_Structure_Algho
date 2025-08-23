#include <iostream>
#include <string>

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *top;
    int size;
    int count;

public:
    Stack(int size) : top(nullptr), size(size), count(0) {}

    void push(T el)
    {
        if (isFull())
        {
            std::cout << "Stack Overflow\n";
            return;
        }
        Node *newNode = new Node(el);
        newNode->next = top;
        top = newNode;
        count++;
    }

    T pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty\n";
            return T();
        }
        Node *temp = top;
        T val = temp->data;
        top = top->next;
        delete temp;
        count--;
        return val;
    }

    T peek(int index)
    {
        if (index <= 0 || index > count)
        {
            std::cout << "Index Out of Bound\n";
            return T();
        }
        Node *current = top;
        for (int i = 1; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    bool isFull() const
    {
        return count == size;
    }
};

bool checkParenthesis(std::string s) {
    Stack<char> stack(5);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(s[i]);
        } else if (s[i] == ')') {
            if (stack.isEmpty()) {
                return false; 
            }
            stack.pop();
        } else {
            continue; 
        }
    }

    return stack.isEmpty(); 
}
bool isBalanced(std::string s) {
    Stack<char> stack(s.length()); // Stack size equal to input length to avoid overflow

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Push opening brackets
        if (ch == '{' || ch == '[' || ch == '(') {
            stack.push(ch);
        }
        // Handle closing brackets
        else if (ch == '}' || ch == ']' || ch == ')') {
            if (stack.isEmpty()) {
                return false; // No matching opening bracket
            }

            char top = stack.pop();

            // Check if the pair matches
            if ((ch == '}' && top != '{') ||
                (ch == ']' && top != '[') ||
                (ch == ')' && top != '(')) {
                return false; // Mismatched pair
            }
        }
    }

    // Stack should be empty if all brackets matched
    return stack.isEmpty();
}


int main()
{
    // Expects to be false or 0
    std::cout<<checkParenthesis("((())))")<<std::endl;
    std::cout<<isBalanced("{{[((}))]}}")<<std::endl;;

    return 0;
}
