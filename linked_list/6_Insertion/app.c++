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

void Insert(Node *p,int pos,int data){
    if(pos <0){
        return ;
    }
    Node *pointer ;
    pointer = new Node;
    pointer = first;

    if(pos = 0){ //*Inserting at pos 0
        pointer->next= first;
        first  = pointer;
    }else 
    {
        for(int i = 0;pos-1;i++){
            p = p->next;
            pointer->next = p->next;
            p->next = pointer;
        }
        
    }
}

void InsertAtTail(Node *p, int value){
    Node *temp = new Node ;
    temp->data = value;
    temp->next = nullptr;
     
     if(first == NULL){
        first = last = temp;

     }else{
        last->next = temp;
        last = temp;
     }

}

