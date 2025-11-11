#include "LinkedList.h"
#include <iostream>
#include <stdio.h>
using namespace std;
void Traverse(Node *START)
{
    Node *p=START;
    while(p!=NULL)
    {
        cout<<p->info;
        p=p->Next;
    }
}
int CountNode(Node *START)
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
void MiddleElement(Node *START)
{
    int c=CountNode(START);
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
void MiddleElement2(Node *START)
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
void Reverse(Node *START)
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
/*void MergeLL(Node *S1,Node *S2)
{
    Node *S3=NULL;
    Node *P=S1,*Q=S2;
    while(P!=NULL&&Q->info)
    {
        if(P->info<Q)
    }
}*/
/***********************************/
int main()
{
 struct Node *START1;
 START1=NULL;
 InsBeg(&START1,'A');
 InsBeg(&START1,'B');
 InsBeg(&START1,'C'); 
 InsBeg(&START1,'D');
 InsBeg(&START1,'E');
 InsBeg(&START1,'F');
 InsBeg(&START1,'G');
 InsBeg(&START1,'H');
 Traverse(START1);
 struct Node *START2;
 START2=NULL;
 InsBeg(&START2,'A');
 InsBeg(&START2,'B');
 InsBeg(&START2,'C'); 
 InsBeg(&START2,'D');
 InsBeg(&START2,'E');
 InsBeg(&START2,'F');
 InsEnd(&START2,'G');
 InsBeg(&START2,'H');
 Traverse(START2);
 Node *p=START1;
 while(p->info!='B')
  p=p->Next;
InsAft(&p,'Z');
Traverse(START1);
 cout<<"Counting of Nodes is"<<CountNode(START1);
 MiddleElement(START1);
 MiddleElement2(START1);

 return 0;
}