#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, int data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    struct Node* temp = stack->top;
    int val = temp->data;
    stack->top = temp->next;
    delete temp;
    return val;
}

void display(struct Stack* stack) {
    struct Node* top = stack->top;
    while (top != NULL) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    struct Stack* stack = new Stack;
    stack->top = NULL;

    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20);

    display(stack);

    pop(stack);

    display(stack);
    return 0;
}
