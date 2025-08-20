
#include<iostream>

/**
 * * in a doubly linked list, each node has a next pointer and a prev pointer
 * 
 */


 struct  Node
 {
    Node * prevNode;
    int  data;
    Node * nextNode;
 }*first=nullptr;
 
Node* createDoubleLs(int arr[],int size){ // Expects a array and size of the arr
    Node *temp , *last;
    temp = new Node;
    last = new Node;
    temp->prevNode=nullptr;
    temp->nextNode = nullptr;
    temp->data = NULL;

    for(int i = 0; i<size; i++){

        temp->data= arr[i];


    }


 }
 /**
  * ! Intialy scan the array, set the last and first points to the same direction  
  * ! take the array element
  * ! use the temp array to hold 
  */