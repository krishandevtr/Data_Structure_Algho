#include <iostream>
#include <climits> // For INT_MIN
#include <cstring> // For strlen()
class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node *top; // points to the top node of the stack
    int size;  // max size of stack
    int count; // current number of elements

public:
    Stack(int size) : top(nullptr), size(size), count(0) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(int el)
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

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty\n";
            return INT_MIN;
        }
        Node *temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        count--;
        return val;
    }

    int peek(int index)
    {
        if (index <= 0 || index > count)
        {
            std::cout << "Index Out of Bound\n";
            return INT_MIN;
        }
        Node *current = top;
        // index 1 means top element, so move index-1 times down
        for (int i = 1; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    bool isFull()
    {
        return count == size;
    }
};

char arr[] = {'a', '+', 'b', 'c', '-', 'd', '/', 'e', '\0'};

char *convert(char *infix)
{
    Stack s1(20);
    char *postFix = new char[strlen(infix) + 1];
    int i = 0,j=0;
    while (infix[i] != '\0')
    {
        if(isOperad(infix[i])){
            postFix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i] > pre(stackTop(s1)))){
                    s1.push(infix[i++]);
            }else{
                postFix[i++] = s1.pop();
            }
        }
    }

    return postFix;
}

char stackTop (Stack s1){
    return 'top';

}
int isOperad(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    return 1;
}

int pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

int main()
{
    std::cout << "Hello" << std::endl;

    return 0;
}

// Infix : Using the binary operators
// for instance a + b

// Prefix the patter is first operator then operand , operand
// +ab

// postfix , operand , operand , operator
// ab+