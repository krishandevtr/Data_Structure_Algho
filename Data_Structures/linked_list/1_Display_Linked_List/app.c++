 #include <iostream>
using namespace std;

//* How to Loop through a linked list 
//* Create a pointer of type Node 
//* Assign the head node to that  , then that temp pointer will points to first node then assign its next to same do some operation then jump to the next node 
//* Use a while loop condition will be while(p-> next!= null){} 

struct Node
{
    int data;
    Node *next;
}*first = NULL;

void createLinks(int arr[], int size) {
    Node *temp, *last;
    
    // Create the first node and assign the first element of the array to it
    first = new Node;
    first->data = arr[0];
    first->next = NULL; // Initialize the next pointer to NULL
    last = first; // The last pointer initially points to the first node

    // Iterate through the array starting from the second element
    for (int i = 1; i < size; i++) {
        // Create a new node for each subsequent element
        temp = new Node;
        temp->data = arr[i]; // Assign the array element to the new node
        temp->next = NULL; // Initialize the next pointer of the new node to NULL

        // Link the new node to the last node in the list
        last->next = temp;
        
        // Update the last pointer to the newly created node
        last = temp;
    }
}


//* Practice 

struct Nodes{
    int data ;
    Nodes *pointer ;
};


void Create(int arr[] , int size){
    Nodes *first;
    Nodes *temp,*last;

    first = new Nodes;

    first->data = arr[0];
    first->pointer = NULL;
    last = first;
    for(int i = 1; i<size; i++){
        temp = new Nodes ;
        temp->data = arr[i];
        temp->pointer = NULL;
        last->pointer = temp;
        last = temp;
    }
}

void Display (Nodes * first){
    Nodes *p = first;
    while(p-> pointer != NULL){
        std::cout<<p->data;
        p =p->pointer;
    }
}

void RecsDisplay (Nodes *p ){//* Tail recursion 

    if(p!= NULL){
        std::cout<<p->data; // * We can change the structure of the code we can first call then print -> Head Recursion
        RecsDisplay(p->pointer);
    }
     
}





int main() {
    int A[] = {3,5,7,10,15};

    
    return 0;
}