#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    char info;
    struct Node *Next;
    struct Node *Prev;
};

/***********************************/
 Node *GetNode()
{
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    return p;
}
/***********************************/
Node* InsBeg(Node *dstart,char x)
{
    struct Node *p;
    p=GetNode();
    p->info=x;
    p->Next=dstart;
    p->Prev=NULL;
    if(dstart!=NULL)
       dstart->Prev=p;
    dstart=p;
    return dstart;
}
/***********************************/
void Traverse(Node *dstart)
{
    struct Node *p=dstart;
    while(p!=NULL)
    {
        cout<<p->info<<",";
        p=p->Next;
    }
}   
/***********************************/
Node *InsEnd(Node *dstart,char x)
{
    
    struct Node *p=GetNode();
    p->info=x;
    p->Next=NULL;
    if(dstart==NULL)
    {
        p->Prev=NULL;
        dstart= p;
    }   
    else
    {
      struct Node *q=dstart;
      while(q->Next!=NULL)
      {
        q=q->Next;
      }
      q->Next=p;
      p->Prev=q;
    }
    return dstart;
}   
/***********************************/
Node *InsAft(Node *dstart,Node *q,char x)
{
    struct Node *p=GetNode();
    p->info=x;
    Node *r=q->Next;
    q->Next=p;
    p->Prev=q;
    p->Next=r;
    if(r!=NULL)
    r->Prev=p;
    return dstart;
}
/***********************************/
Node *InsBef(Node *dstart,Node *q,char x)
{
    struct Node *p=GetNode();
    p->info=x;
     Node *r=q->Prev;
        q->Prev=p;
        p->Next=q;
        p->Prev=r;
    if(r!=NULL)
        r->Next=p;
    return dstart;
}
/*************************/
Node *DelBeg(Node *dstart)
{
    if(dstart==NULL)
    {
        cout<<"Void Deletion";
        exit(1);
    }
    else
    {
    struct Node *p=dstart;
    dstart=dstart->Next;
    if(dstart!=NULL)
    dstart->Prev=NULL;
    int x=p->info;
    free(p);
    }
    return dstart;
}
/*******************************/
Node *DelEnd(Node *dstart)
{
    if(dstart==NULL)
    {
        cout<<"Void Deletion";
        exit(1);
    }
    else
    {
        struct Node *p=dstart;
        while(p->Next!=NULL)
        {
            p=p->Next;
        }
        Node *q=p->Prev;
        if(q->Next!=NULL)
          q->Next=NULL;
        else
        dstart=NULL;
        int x=p->info;
        free(p);
    }
    return dstart;
}
/*******************************/
Node *DelAft(Node *dstart,Node *q)
{
    if(q->Next==NULL||q==NULL)
    {
        cout<<"Void Deletion";
        exit(1);
    }
    else
    {
        struct Node *p=q->Next;
        Node *r=p->Next;
        q->Next=r;
        if(r!=NULL)
         r->Prev=q;
        int x=p->info;
        free(p);
    }
    return dstart;
}
/*******************************/
int main()
{
    Node *dstart;
    dstart=NULL;
    dstart=InsBeg(dstart,'A');
    dstart=InsBeg(dstart,'B');
    dstart=InsBeg(dstart,'C');
    dstart=InsBeg(dstart,'D');  
    dstart=InsBeg(dstart,'E');
    dstart=InsBeg(dstart,'F');
    dstart=InsBeg(dstart,'G');  
    dstart=InsEnd(dstart,'W');
    dstart=InsEnd(dstart,'X');      
    dstart=InsEnd(dstart,'Y');
    dstart=InsEnd(dstart,'Z');
    Traverse(dstart);
    cout<<"\n";
    Node *tmp=dstart;
    while(tmp->info!='C')
      tmp=tmp->Next;
    dstart=InsAft(dstart,tmp,'+');
    dstart=InsBef(dstart,tmp,'-');
   Traverse(dstart);
   cout<<"\n";
   dstart=DelBeg(dstart);
   Traverse(dstart);
   cout<<"\n";
   dstart=DelEnd(dstart);   
   Traverse(dstart);
   cout<<"\n";
   Node *a=dstart;
   while(a->info!='W')
      a=a->Next;
    dstart=DelAft(dstart,a);
    Traverse(dstart);
    cout<<"\n";
    return 0;
}