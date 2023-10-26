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

Node* insert(Node* &head, string s) {
    Node* n = new Node(s);
    if (head == NULL) head = n;
    else {
        Node* temp= head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
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

Node* reverse(Node* &head) {
    Node*c = head;
    Node* n = NULL;
    Node* p = NULL;
    while (c != NULL) {
        n = c->next;
        c->next = p;
        p = c; c = n;
    }
    return p;
}

int main() {
    Node* head = NULL;
    head = insert(head, "abc");
    head = insert(head, "def");
    head = insert(head, "gh");
    head = insert(head, "ijk");
    head = insert(head, "lmn");

    cout << "Original: ";
    display(head);
    cout << "Reversed: ";
    display(reverse(head));
    
    return 0;
}