#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* next;
};

void insertEnd(node* &head, int value) {
node* newNode = new node;
newNode->data = value;
newNode->next = NULL;

if (head == NULL) {
head = newNode;
return;
}

node* temp = head;
while (temp->next != NULL)
temp = temp->next;

temp->next = newNode;
}

void traversal(node* head){
node* temp=head;
int count=0;
while(temp!=NULL){
cout<<temp ->data<<"->";
temp=temp ->next;
count=count+1;
}
cout<<"NULL\n";
}

int Search(node* head, int key){
node* temp=head;
int flag=0;
while(temp!=NULL){
if(temp->data==key){
flag=1;
}
temp=temp->next;

}
if(flag==1){
cout<<"node found";
}else{
cout<<"not found";
}
return 0;
}

int main(){
node* head=NULL;
int n,value;
cout << "Enter number of nodes: ";
cin >> n;

cout << "Enter elements: ";
for (int i = 0; i < n; i++) {
cin >> value;
insertEnd(head, value);
}
cout<<"Linked list is:";
traversal(head);
int key;
cout<<"Enter value to find:";
cin>>key;
Search(head,key);

return 0;
}

