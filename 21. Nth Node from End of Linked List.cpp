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

Node* nthFromEnd(Node* head, int n) {
    Node* temp = head;
    for (int i=0; i<n; i++) {
        temp = temp->next;
    }
    while (temp != NULL) {
        temp = temp->next;
        head = head->next;
    }
    cout << n << "th element from end is: " << head->s << endl;
    return head;
}

int main() {
    Node* head = NULL;
    head = insert(head, "abc");
    head = insert(head, "def");
    head = insert(head, "ghi");
    head = insert(head, "jkl");
    head = insert(head, "mno");
    display(head);
    nthFromEnd(head, 3);
    return 0;
}