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
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
    return n;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->s << " ";
        head = head->next;
    }
    cout << endl;
}

bool hasCycle(Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next->next;
        head = head->next;
        if (temp == head) {
            temp->next = NULL;
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = new Node("abc");
    Node* n1 = insert(head, "def");
    Node* n2 = insert(head, "gh");
    Node* n3 = insert(head, "ijk");
    n3->next = n1;

    if (hasCycle(head)) {
        cout << "Has Cycle. Removed" << endl;
        // display(head);
    }
    else cout << "No Cycle" << endl;
    display(head);
    
    return 0;
}