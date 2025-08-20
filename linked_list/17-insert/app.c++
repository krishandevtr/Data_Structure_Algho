
struct Node
{
    int Data;
    Node *next;
}*head;

void insert(Node *p,int pos,int data,int size ){
    Node *t;
    for(int i = 0; i<pos-1;i++){
        p=p->next;
        t = new Node;
        t->Data = data;
        t->next = p->next;
        p->next = t;


    }


}