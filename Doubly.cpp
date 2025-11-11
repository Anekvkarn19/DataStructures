#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

node* createnode(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void traversal(node* head) {
    node* temp = head;
    int count = 0;
    while (temp != NULL) {
        cout << "Data stored in node: " << temp->data << endl;
        temp = temp->next;
        count++;
    }
    cout << "Total nodes: " << count << endl;
}

void Insbeg(node* &head, int value) {
    node* newnode = createnode(value);
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}

void Insend(node* &head, int value) {
    node* newnode = createnode(value);
    if (head == NULL) {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void InsAfter(node* &head, int key, int value) {
    node* temp = head;
    for (int i = 0; i < key; i++)
        temp = temp->next;

    node* newnode = createnode(value);
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

void InsBefore(node* &head, int key, int value) {
    node* temp = head;
    for (int i = 0; i < key - 1; i++)
        temp = temp->next;

    node* newnode = createnode(value);
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

void delBeg(node* &head) {
    node* temp = head;
    cout << temp->data << " deleted from beginning\n";
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void delEnd(node* &head) {
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << temp->data << " deleted from end\n";
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    delete temp;
}

void delAfterNode(node* &head, int key) {
    node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    node* bin = temp->next;
    temp->next = bin->next;
    if (bin->next != NULL)
        bin->next->prev = temp;

    cout << bin->data << " deleted successfully\n";
    delete bin;
}

int main() {
    node* head = NULL;
    int n, val, x = 0;

    while (x != -1) {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insertion at end\n";
        cout << "2. Insertion at beginning\n";
        cout << "3. Display list\n";
        cout << "4. Insert after a position\n";
        cout << "5. Insert before a position\n";
        cout << "6. Delete from beginning\n";
        cout << "7. Delete from end\n";
        cout << "8. Delete after a node (by value)\n";
        cout << "9. Exit\n";
        cout << "Choice: ";
        cin >> x;

        switch (x) {
            case 1:
                cout << "No. of nodes: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter value for node " << i + 1 << ": ";
                    cin >> val;
                    Insend(head, val);
                }
                traversal(head);
                break;

            case 2:
                cout << "Enter value for new node: ";
                cin >> val;
                Insbeg(head, val);
                break;

            case 3:
                cout << "Stored linked list:\n";
                traversal(head);
                break;

            case 4: {
                int key, value;
                cout << "Enter position (0-based): ";
                cin >> key;
                cout << "Enter value for new node: ";
                cin >> value;
                InsAfter(head, key, value);
                break;
            }

            case 5: {
                int key, value;
                cout << "Enter position (0-based): ";
                cin >> key;
                cout << "Enter value for new node: ";
                cin >> value;
                InsBefore(head, key, value);
                break;
            }

            case 6:
                delBeg(head);
                break;

            case 7:
                delEnd(head);
                break;

            case 8: {
                int value;
                cout << "Enter node value after which deletion should happen: ";
                cin >> value;
                delAfterNode(head, value);
                break;
            }

            case 9:
                x = -1;
                break;

            default:
                break;
        }
    }

    return 0;
}
