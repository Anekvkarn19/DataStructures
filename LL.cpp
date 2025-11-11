#include<iostream>
using namespace std;
 struct node{
        int data;
        node*next;

 };
 node*create(int val){
    node*temp=new node;
    temp->data=val;
    temp->next=NULL;
    return temp;
    
 }

void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(node*&head,int data){
   node*temp=create(data);
   temp->next=head;
   head=temp;
}
void insertattail(node*&tail,int data)
{
node*temp=create(data);
tail->next=temp;
temp=tail;
}
void insertafternode(node*&head,int val,int data){
    node*temp=head;
    while(temp->data!=val){
        temp=temp->next;
    }
    node*temp2=create(data);
    temp2->next=temp->next;
    temp->next=temp2;

}
void deletehead(node*&head){
    node*temp=head;
    head=head->next;
    temp->next=NULL;
}
void deletetail(node*&head){
    node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node*q=temp;
    q->next=NULL;
}
void deleteafternode(node*&head,int val){
    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node*q=temp;
    q->next=temp->next->next;
    temp->next->next=NULL;
}
int main(){
node*head=create(5);
node*tail=head;
print(head);
insertathead(head,6);
print(head);
insertattail(tail,9);
print(head);
insertafternode(head,5,4);
print(head);
deletehead(head);
print(head);

return 0;
}
