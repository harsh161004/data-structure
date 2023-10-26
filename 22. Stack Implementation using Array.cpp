#include <iostream>
using namespace std;

struct Stack {
    int* arr;
    int top;
    int capacity;
};

Stack* createStack(int capacity) {
    Stack* stack = new Stack;
    stack->capacity = capacity;
    stack->arr = new int[capacity];
    stack->top = -1;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        cout << "StackOverflow" << endl;
        return;
    }
    stack->arr[++(stack->top)] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Underflow" << endl;
        return -1;
    }
    return stack->arr[(stack->top)--];
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        cout << stack->arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack* stack = createStack(5);

    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20);

    display(stack);

    pop(stack);

    display(stack);
    return 0;
}