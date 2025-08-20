
 #include <iostream>
using namespace std;
class Node{
    public:
        int Data;
        Node *next;
};

class LinkedList{
    private:
        Node *first;
    public:
        LinkedList(){
            first = nullptr;
        }
        LinkedList(int arr[],int n);
        ~LinkedList();
        void Display();
        void Insert(int index,int value);
        void Delete(int pos);
        int Length();


};

LinkedList ::LinkedList(int arr[],int n){
    Node *last ,*t;
    int i = 0;

    first = new Node;
    first->Data= arr[0];
    last = first;

    for(i;i<n;i++){
        t = new Node;
        t->Data = arr[i];
        last->next = NULL;
        last ->next = t;
        last = t;
    }
}


LinkedList::~LinkedList(){
    Node * p=first;
    while(first){
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display( ){
    Node *p = first;
    while(p ){
        std::cout<<p->Data<<std::endl;
        p = p->next;
    }

}

int LinkedList::Length(){
    Node *p = first;
    int count = 0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

void LinkedList::Insert(int index,int value){
    Node *t,*p = first;
    t =new Node;
    t->Data = value;
    t->next = nullptr;

    if(index = 0){ //*Inserting at index 0
        first  = t;
    }else 
    {
        for(int i = 0;index-1;i++){
            p = p->next;
            t->next = p->next;
            p->next = t;
        }
        
    }

}

void LinkedList::Delete(int pos){
        Node *p = first;
    Node *temp = nullptr;

    for(int i = 0; i<pos-1;i++){
         temp = p;
         p = p->next; 
    }
    temp->next = p->next;
    delete p;
}


int main() {
    // Your code here
    return 0;
}