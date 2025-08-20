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

bool isDuplicates(Node *first) {
    Node *checker = first;

    while (checker != nullptr && checker->next != nullptr) {
        if (checker->data == checker->next->data) {
            return true; // Duplicate found
        }
        checker = checker->next; // Move to the next node
    }

    return false; // No duplicates found
}

void removeDuplicated(Node *p){
    Node *pointer = first;
    Node *temp = first->next;

    if(pointer->data != temp->data){
        pointer = temp;
        temp = temp->next;
    }else{
        pointer->next = temp->next;
        delete temp;
        temp = pointer->next;
    }
    
}

