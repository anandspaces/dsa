#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

class Llist {
private:
    Node* Head;
    void Recursive_Traverse(Node* tmp) {
        if (tmp == NULL)
            return;
        cout << tmp->data << "\t";
        Recursive_Traverse(tmp->link);
    }

public:
    Llist() {
        Head = NULL;
    }

    ~Llist() {
        Node* Temp;
        while (Head != NULL) {
            Temp = Head;
            Head = Head->link;
            delete Temp;
        }
    }

    void Create();
    void Display();
    Node* GetNode();
    void Append(Node* NewNode);
    void R_Traverse() {
        Recursive_Traverse(Head);
        cout << endl;
    }
};

void Llist::Create() {
    char ans;
    Node* NewNode;
    while(true) {
        cout << "Any more nodes to be added (Y/N)";
        cin >> ans;
        if(ans == 'y' || ans == 'Y') {
            NewNode = GetNode();
            Append(NewNode);
        } else {
            break;
        }
    }
}

void Llist::Append(Node* NewNode) {
    if (Head == NULL) {
        Head = NewNode;
    }
    else {
        Node* temp = Head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = NewNode;
    }
}

Node* Llist::GetNode() {
    Node* Newnode = new Node;
    cin >> Newnode->data;
    Newnode->link = NULL;
    return Newnode;
}

void Llist::Display() {
    Node* temp = Head;
    if (temp == NULL) {
        cout << "Empty List";
    }
    else {
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->link;
        }
    }
    cout << endl;
}

int main() {
    Llist L1;
    L1.Create();
    L1.Display();
    return 0;
}
