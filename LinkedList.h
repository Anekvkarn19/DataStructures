#include <stdlib.h>
struct Node
{
 char info;
 struct Node *Next;
};

Node * GetNode()
{
    Node *p;
    p=(Node*)malloc(sizeof(struct Node));
    return p;
}

void InsBeg(Node **START,char x)
{
    Node *p;
    p=GetNode();
    p->info=x;
    p->Next=*START;
    *START=p;
}

void InsEnd(Node **START,char x)
{
    Node *q=*START;
    Node *p=GetNode();
    p->info=x;
    p->Next=NULL;
    while(q->Next!=NULL)
    {
        q=q->Next;
    }
    q->Next=p;
}
void InsAft(Node **Q,char x )
{
  Node *P= GetNode();
  P->info=x;
  Node *R=(*Q)->Next;
  (*Q)->Next=P;
  P->Next=R;
}
