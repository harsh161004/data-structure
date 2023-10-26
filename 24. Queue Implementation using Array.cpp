#include <iostream>
using namespace std;

struct Queue {
    int* arr;
    int front;
    int rear;
    int capacity;
};

Queue* createQueue(int capacity) {
    Queue* queue = new Queue;
    queue->capacity = capacity;
    queue->arr = new int[capacity];
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

bool isFull(Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        cout << "Overflow" << endl;
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->arr[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Underflow" << endl;
        return -1;
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return value;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = queue->front;
    while (true) {
        cout << queue->arr[i] << " ";
        if (i == queue->rear) break;
        i = (i + 1) % queue->capacity;
    }
    cout << endl;
}

int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);

    display(queue);

    dequeue(queue);

    display(queue);
    
    delete[] queue->arr;
    delete queue;
    return 0;
}
