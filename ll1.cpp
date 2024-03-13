// initializing a linked list
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head,int val) {
    Node* n = new Node(val);
    Node* temp = head;
    if(head == NULL) {
        head = n;
        return;
    }
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAtHead(Node* &head,int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}
void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data <<"\t";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);    
    return 0;
}
