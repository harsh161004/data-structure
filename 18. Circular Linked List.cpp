#include <iostream> 
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

Node* insert(Node* last, string s)  { 
    if (last == NULL) {
        Node* temp = new Node(s);
        last = temp; 
        last->next = last;
        return last; 
    }

    Node* temp = new Node(s);
	temp->next = last->next;
	last->next = temp; 
	last = temp; 
	return last;
} 

void display(Node* last) 
{ 
	Node* p; 

	if (last == NULL) return; 

	p = last->next; 
    cout << p->s << " ";
    p = p->next;
	while (p != last->next) { 
		cout << p->s << " "; 
		p = p->next; 
	}
    cout << endl;
} 

int main() 
{ 
	Node* last = NULL; 
	last = insert(last, "abc"); 
	last = insert(last, "def"); 
	last = insert(last, "ghi"); 
	last = insert(last, "jkl"); 
	last = insert(last, "mno"); 

	display(last); 
	return 0; 
}
