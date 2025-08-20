#include<vector> 
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

bool isLoop(Node *&first){
        Node * p , *q;
         p = first;
         q = nullptr;
         
         do{
            p = p->next;
            q= q->next;
            q = q!=nullptr?q->next:nullptr;

         }while(p && q);

        return p== q? true:false;
         
}