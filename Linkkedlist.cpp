#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
 char info;
 struct Node *Next;
};
struct Node *START;
/***********************************/
Node * GetNode()
{
    Node *p;
    p=(Node*)malloc(sizeof(struct Node));
    return p;
}
/***********************************/
void InsBeg(char x)
{
    Node *p;
    p=GetNode();
    p->info=x;
    p->Next=START;
    START=p;
}
/***********************************/
void Traverse()
{
    Node * p=START;
    while(p!=NULL)
    {
        cout<<p->info;
        p=p->Next;
    }
}
/***********************************/
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
void InsAft(Node **Q,char x )
{
  Node *P= GetNode();
  P->info=x;
  Node *R=(*Q)->Next;
  (*Q)->Next=P;
  P->Next=R;
}
void OrderedInsertion(int x)
{
  Node *P,*Q;
  P=START;
  Q=NULL;

}
/***********************************/
int CountNode()
{
    int c=0;
    Node *p;
    p=START;
    while(p!=NULL)
    {
        c++;
        p=p->Next;
    }
    return c;
}
/***********************************/
void MiddleElement()
{
    int c=CountNode();
    int i=1;
    Node *p=START;
    for(int i=1;i<c/2;i++)
    {
        p=p->Next;
    }
    if(c%2!=0)
     p=p->Next;

    cout<<"\n\n Middle element is =>"<<p->info<<endl;
}
/***********************************/
void MiddleElement2()
{
    Node *T,*R;
    T=START;
    R=START->Next;
    while(R!=NULL&& R->Next!=NULL)
    {
        T=T->Next;
        R=R->Next;
        R=R->Next;
    }
    cout<<"\n\nMiddle Element is=>"<<T->info<<endl;
}
/***********************************/
void Reverse()
{
    Node *P=NULL;
    Node *C=START;
    Node *N=C->Next;
    while(C!=NULL)
    {
        C->Next=P;
        P=C;
        C=N;
        if(N!=NULL)
        N=N->Next;
    }
    START=P;
}
/***********************************/
char DelBeg()
{
    Node *P=START;
    START=START->Next;
    char x=P->info;
    free(P);
    return x;
}
/***********************************/
char DelAft(Node **Q)
{
    Node *P=(*Q)->Next;
    Node *R=P->Next;
    (*Q)->Next=R;
    char x=P->info;
    free(P);
    return x;
}
/***********************************/
char DelEnd()
{
  Node *Q=NULL;
  Node *P=START;
  while(P!=NULL&&P->Next!=NULL)
  {
    Q=P;
    P=P->Next;
  }
  char x=P->info;
  Q->Next=NULL;
  free(P);
  return x;
}
/******************************/



/*******************************/
int main()
{
    
 START=NULL;
 InsBeg('A');
 InsBeg('B');
 InsBeg('C'); 
 InsBeg('D');
 InsBeg('E');
 InsBeg('F');
 InsBeg('H');
 InsEnd('G');
 Traverse();
 int c=CountNode();
 cout<<"\n\n Number of Nodes"<<c;
 //MiddleElement();
 //MiddleElement2();
 char d=DelBeg();
 cout<<"\n\n Linked List at the beginning is =>"<<endl;
 Traverse();
 //cout<<"Deleted first Node is =>"<<d<<endl;
 //cout<<"Deleted end node is=>"<<DelEnd()<<endl;
 //cout<<"Deleted node is=>"<<endl;

 Reverse();
 cout<<"\n\n Reversed Linked List is =>"<<endl;
 Traverse();
 return 0;
}
