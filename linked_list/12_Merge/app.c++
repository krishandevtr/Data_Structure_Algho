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
//* Merge two sorted linked list 

void merge(Node *first,Node *second){
    Node *third,*last;
    if(first->data<second->data){
        third= last = first;
        first = first ->next;
        last ->next = nullptr;
    }else{
        third= last = first;
        second = second ->next;
        last ->next = nullptr;
    }


    while(first && second){
        if(first->data<second->data ){
            last->next = first;
            last = first;
            first = first->next;
            last ->next = nullptr;

        }else{
            last->next = second;
            last = second;
            second = second->next;
            last ->next = nullptr;
        }

    }
    if(first) last->next = first;
    if(second) last->next = second;

}
