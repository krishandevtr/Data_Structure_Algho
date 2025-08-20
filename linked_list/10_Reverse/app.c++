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

void reverse(Node *p,int size){
    vector<int> Aux;//*N
    Node *temp = first;

    while(p!=nullptr){
        int x = temp->data;
        Aux.push_back(x);
        temp = temp->next;
    }//*N
    temp = first;

    for(int i = Aux.size()-1; i>=0;i++){
        temp->data = Aux[i];
        temp = temp->next;
    }//*N   
}

void Reverse(Node *&first) {
    Node *p = first;
    Node *q = nullptr;
    Node *r = nullptr;

    while (p != nullptr) {
        r = q;       // Save the previous node
        q = p;       // Move q to the current node
        p = p->next; // Move to the next node
        q->next = r; // Reverse the link
    }
    first = q; // Update the head of the reversed list
}

void recReverse(Node *q,Node *p){
    if(p!= nullptr){
        recReverse(p,p->next);
        p->next = q; 

    }else{
        first = q;

    //* return p == null ? first = q;: r(p,p->next);
    //*  if (p!=nullptr)p->next = q;


    }




}