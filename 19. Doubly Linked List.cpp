#include<iostream>
using namespace std;

class Node {
    public:
        Node* next;
        Node* prev;
        int data;

        Node(int d) {
            next = NULL;
            prev = NULL;
            data = d;
        }
};

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int length(Node* head) {
    int i = 0;
    while (head->next != NULL) {
        head = head->next;
        i++;
    }
    return i;
}

Node* insertAtEnd(Node* &head,int data) {
    Node* n = new Node(data);
    if (head == NULL) head = n;
    else {
        Node*temp =head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }
    return head;
}

Node* insertAtHead(Node* &head,int data) {
    Node* n = new Node(data);
    if (head == NULL) head = n;
    else {
        Node* temp = head;
        n->next = temp;
        temp->prev = n;
        head = n;
    }
    return head;
}

Node* deleteAtHead(Node* &head) {
    if (head == NULL || head->next == NULL) delete head;
    else {
        Node*temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

Node* deleteAtTail(Node* &head) {
    if (head == NULL || head->next == NULL) delete head;
    else {
        Node*temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        Node*temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
    }
    return head;
}

Node* insertAtPosition(Node* &head,int data,int k,int z) {
    Node*n = new Node(data);
    if (k == 0) {
        insertAtHead(head,data);
        return head;
    }
    if (k == z) {
        insertAtEnd(head,data);
        return head;
    }

    Node*temp = head;
    for (int i=0; i<k-1; i++) temp = temp->next;
    
    Node*temp2 = temp->next;
    temp->next = n;
    n->prev = temp;
    n->next = temp2;
    temp2->prev = n;
    return head;
}

Node* deleteAtPosition(Node* &head, int k, int z) {
    if (k == 0) {
        deleteAtHead(head);
        return head;
    }

    if (k == z) {
        deleteAtTail(head);
        return head;
    }

    Node* temp=head;
    for(int i=0; i<k-1; i++) temp=temp->next;

    Node* temp2 = temp->next;
    Node* temp3 = temp->next->next;
    temp->next = temp3;
    temp3->prev = temp;
    
    delete temp2;
    return head;
}


int main() {
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtHead(head, 5);
    insertAtEnd(head,6);
    insertAtEnd(head,7);
    insertAtEnd(head,8);
    cout << "Doubly Linked List: ";
    display(head);
    deleteAtHead(head);
    cout << "Delete At Head: ";
    display(head);
    deleteAtPosition(head,3,length(head));
    cout << "Delete At Position 3: ";
    display(head);
    deleteAtTail(head);
    cout << "Delete at Tail: ";
    display(head);
    cout << "Insert At Position 3: ";
    insertAtPosition(head,3,length(head)-1,length(head));
    display(head);
    
    return 0;
}