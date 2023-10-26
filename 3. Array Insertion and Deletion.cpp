#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(int arr[], int& size, int position, int element) {
    if (size == MAX_SIZE) {
        cout << "Overflow (Array is Full)" << endl;
        return;
    }

    if (position > MAX_SIZE) {
        cout << "Invalid Position" << endl;
        return;
    }

    for (int i=size-1; i>=position; i--) {
        arr[i+1] = arr[i];
    }

    arr[position] = element;
    size++;
}

void del(int arr[], int& size, int position) {
    if (size == 0) {
        cout << "Underflow (Empty Array)" << endl;
        return;
    }

    for (int i=position; i<size-1; i++) {
        arr[i] = arr[i+1];
    }

    size--;
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << "Original array: ";
    display(arr, size);

    insert(arr, size, 2, 10);
    cout << "After insertion at position 2: ";
    display(arr, size);

    del(arr, size, 3);
    cout << "After deletion at position 3: ";
    display(arr, size);

    insert(arr, size, 4, 20);
    cout << "After insertion at position 4: ";
    display(arr, size);

    return 0;
}
