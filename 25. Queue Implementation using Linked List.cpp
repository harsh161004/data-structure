#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    struct Node* temp = queue->front;
    int val = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    delete temp;
    return val;
}

void display(struct Queue* queue) {
    struct Node* front = queue->front;
    while (front != NULL) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << endl;
}

int main() {
    struct Queue* queue = new Queue;
    queue->front = queue->rear = NULL;

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);

    display(queue);

    dequeue(queue);

    display(queue);

    delete queue;
    return 0;
}
