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

void reverse(node* &head) {
    node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;  
        current->next = prev;   
        prev = current;         
        current = next;         
    }

    head = prev; 
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

    reverse(head);

    cout << "Reversed List: ";
    traversal(head);
    return 0;
}


