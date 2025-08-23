//* why Linked List 

/**
 * * Problems with array 
 * ! Array is  fixed size , once created you cannot change the size of the array 
 * * Difference between Array and linked list 
 * ! The Linked list can grow dynamically using the pointer
 * !  
 */

//* About the Linked list 
/**
 * ! simply we can say linked list a collection where each node have some data and a pointer that points to another node 
 * ! How to crete a single node 
 *  */
 #include <iostream>
using namespace std;
struct  Node
{
    int data;
    Node *next;
};



int main() {
    Node *p = new Node;
    p-> data = 5;
    p-> next = 0;
    return 0;
}



