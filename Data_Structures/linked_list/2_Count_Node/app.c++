#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*first;
void Create(int arr[],int size){
    first  = new Node;
    Node * temp,*last;
    first-> data = arr[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i<size;i++){
        temp  = new Node ;
        temp-> data = arr[i];
        temp-> next = NULL;
        last->next = temp;
        last = temp;
    }
}


//* 
int Count (Node *first){
     int count = 0;
    while(first-> next != 0){
        count ++;
        first = first->next;
    }
    return count;
}

int numberOfNode(Node *first){ 
    if(first == NULL){
        return 0 ;
    }
     return 1+ numberOfNode(first->next); //* return numberCount +1;
}



int main() {
    
    return 0;
}
