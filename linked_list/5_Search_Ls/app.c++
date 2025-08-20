#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *first;
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

Node* LinearSearch(Node* p, int key) {
    while (p != nullptr) {
        if (p->data == key) {
            return p; // Return the node containing the key
        }
        p = p->next; // Move to the next node
    }
    return nullptr; // Key not found
}//* There is a chance to improve the ls one is to transposition or Move to head 

Node * LS(Node *p,int key){
    if(p ==nullptr) {
        return nullptr;
    }
    return p->data == key? p: LS(p->next,key);
    

}


int main() {
   
    return 0;
}