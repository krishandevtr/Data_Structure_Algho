#include<iostream> 
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first,*last;
void Create(int arr[], int size)
{
    first = new Node;
    Node *temp, *last;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

bool isSorted(Node *first) {
    Node *checker = first;
    // Traverse the list while comparing current node with the next node
    while (checker != nullptr && checker->next != nullptr) {
        if (checker->data > checker->next->data) {
            return false; // List is not sorted
        }
        checker = checker->next; // Move to the next node
    }
    return true; // List is sorted
}


