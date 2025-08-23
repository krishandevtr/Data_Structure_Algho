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


void DeleteFirst(Node *p , int value ){
    Node *p = first;
    first = first->next;
    int x = p->data; // Take the data of the node
    delete p;
}

void Delete(Node *p,int pos){
    Node *p = first;
    Node *temp = nullptr;

    for(int i = 0; i<pos-1;i++){
         temp = p;
         p = p->next; 
    }
    temp->next = p->next;
    delete p;
}