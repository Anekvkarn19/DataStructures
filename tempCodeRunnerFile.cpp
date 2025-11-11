#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
 char info;
 struct Node *Next;
};
struct Node *START;
Node * GetNode()
{
    Node *p;
    p=(Node*)malloc(sizeof(struct Node));
    return p;
}
void InsBeg(char x)
{
    Node *p;
    p=GetNode();
    p->info=x;
    p->Next=START;
    START=p;
}
void Traverse()
{
    int c=0;
    Node * p=START;
    while(p!=NULL)
    {
        c++;
        cout<<p->info;
        p=p->Next;
    }
    cout<<" Number of nodes "<<c;
}
void InsEnd(char x)
{
    Node *q=START;
    Node *p=GetNode();
    p->info=x;
    p->Next=NULL;
    while(q->Next!=NULL)
    {
        q=q->Next;
    }
    q->Next=p;
}
int main()
{
 START=NULL;
 InsBeg('A');
 InsBeg('B');
 InsBeg('C'); 
 InsBeg('D');
 InsBeg('E');
 InsBeg('F');
 InsEnd('G');
 Traverse();
 return 0;
}