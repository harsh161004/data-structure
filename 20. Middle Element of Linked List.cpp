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

Node* middleElement(Node* head) {
    Node* temp = head;
    while (temp != NULL and temp->next != NULL) {
        temp = temp->next->next;
        head = head->next;
    }
    cout << "Middle element is: " << head->s << endl;
    return head;
}

int main() {
    Node* head = NULL;
    head = insert(head, "abc");
    head = insert(head, "def");
    head = insert(head, "ghi");
    head = insert(head, "jkl");
    head = insert(head, "mno");
    head = insert(head, "pqr");
    head = insert(head, "stu");
    display(head);
    middleElement(head);
    return 0;
}