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


int MaxEl(struct Node *p){
    int max = INT_MIN;
    if(p == 0) return -1;

    while(p!= NULL){
        if(p->data > max) max = p->data;
        p = p->next;
    }
    return max;

}

int recMax(Node *p){
    int temp ;
    if(p == 0) return INT_MIN;
        temp = recMax(p->next);
        return temp>p->data ? temp: p->data;

}