#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int Data;
    Node *next;
} *head;

void Display(Node *p)
{
    do
    {
        cout << (p->Data) << endl;
        p = p->next;
    } while (p->next != head);
}

void display(Node *p){
    static int flag = 0;
    if(flag == 0 || p!=head){
        flag= 1;
        cout<<p->Data<<endl;
        display(p->next);
    }
    flag = 0;
}

int main()
{
    return 0;
}