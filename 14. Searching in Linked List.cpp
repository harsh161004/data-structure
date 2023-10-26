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
    if (head == NULL) head=n;
    else {
        Node* temp= head;
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

int search(Node* head, string key) {
    int pos = 0;
    while (head->next != NULL) {
        if (head->s == key) return pos;
        head = head->next;
        pos++;
    }
    return pos;
}

int main() {
    Node* head = new Node("mno");
    insert(head, "jkl");
    insert(head, "ghi");
    insert(head, "def");
    insert(head, "abc");
    display(head);

    cout << "jkl is at index: " << search(head, "jkl") << endl;    
    return 0;
}