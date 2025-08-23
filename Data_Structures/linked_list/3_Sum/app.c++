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

int Sum(Node *p)
{
    int sum = 0;
    if (p == NULL)
        return -1;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sum(Node *p)
{
    int  x = 0;
    if (p == NULL)
    {
        return;
    }
    else
    {  
        return p->data + sum(p->next);
    }
}