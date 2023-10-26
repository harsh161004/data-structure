#include<iostream>
using namespace std;

class Node {
    public:
        Node* next;
        int data;
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

Node* insert(Node* &head, int data) {
    Node* n = new Node(data);
    if (head == NULL) head = n;
    else {
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
    return n;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* merge(Node* head1, Node* head2) {
    Node *temp, *final_head;

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data < head2->data) {
        temp = new Node(head1->data);
        head1 = head1->next;
    }
    else {
        temp = new Node(head2->data);
        head2 = head2->next;
    }

    final_head = temp;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            temp->next = new Node(head1->data);
            head1 = head1->next;
        } else {
            temp->next = new Node(head2->data);
            head2 = head2->next;
        }
        temp = temp->next;
    }

    while (head1 != NULL) {
        temp->next = new Node(head1->data);
        head1 = head1->next;
        temp = temp->next;
    }

    while (head2 != NULL) {
        temp->next = new Node(head2->data);
        head2 = head2->next; 
        temp = temp->next;
    }

    return final_head;
}

int main() {
    Node* head1 = new Node(1);
    insert(head1, 3);
    insert(head1, 6);
    insert(head1, 8);

    Node* head2 = new Node(4);
    insert(head2, 5);
    insert(head2, 7);
    insert(head2, 12);
    
    display(head1);
    display(head2);

    cout << "Merged: ";
    Node* head3 = merge(head1, head2);
    display(head3);
    return 0;
}