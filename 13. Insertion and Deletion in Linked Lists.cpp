#include<iostream>
using namespace std;

class Node {
    public:
        Node* next;
        string s;
        Node(string s) {
            this->s = s;
            next = NULL;
        }
};

Node* insertAtTail(Node* &head, string s) {
    Node* n = new Node(s);
    if (head == NULL) head = n;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp=temp->next;
        temp->next = n;
    }
    return head;
}

Node* insertAtHead(Node* &head, string s) {
    Node* n = new Node(s);
    if (head == NULL) head = n;
    else {
        n->next = head;
        head = n;
    }
    return head;
    
}

Node* deleteAtHead(Node* &head) {
    if (head == NULL || head->next == NULL) head = nULL;
    else {
        Node* temp = head;
        temp = temp->next;
        delete head;
        head = temp;
    }
    return head;
}

Node* deleteAtTail(Node* &head) {
    if (head == NULL || head->next == NULL) head = NULL;
    else {
        Node* temp = head;
        while (temp->next->next != NULL) temp=temp->next;
        Node* temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
    }
    return head;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->s << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteAtPosition(Node* &head,int position) {
    Node* temp = head;
    for (int i=0; i<position-1; i+=1) temp=temp->next;
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

int main() {
    Node* head = NULL;
    head = insertAtHead(head, "abc");
    head = insertAtHead(head, "def");
    head = insertAtHead(head, "lmn");
    display(head);
    head = insertAtHead(head, "ijk");
    cout << "Insertion at Head: ";
    display(head);
    cout << "Insertion at Tail: ";
    head = insertAtTail(head, "gh");
    display(head);
    cout << "Deletion at Head and Tail: "
    head = deleteAtHead(head);
    head = deleteAtTail(head);
    display(head);
    cout << "Deletion at Position: "
    deleteAtPosition(head, 2);
    display(head);

    return 0;
}