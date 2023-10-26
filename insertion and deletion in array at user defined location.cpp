#include <iostream>
using namespace std;

int main() {
    int array[100];
    int size, position, element;

    // Input array size
    cout << "Enter the size of the array: ";
    cin >> size;

    // Input array elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Insertion at user-defined position
    cout << "Enter the position for insertion: ";
    cin >> position;
    cout << "Enter the element to insert: ";
    cin >> element;

    if (position < 0 || position > size) {
        cout << "Invalid position for insertion." << endl;
    } else {
        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = element;
        size++;
    }

    // Deletion at user-defined position
    cout << "Enter the position for deletion: ";
    cin >> position;

    if (position < 0 || position >= size) {
        cout << "Invalid position for deletion." << endl;
    } else {
        for (int i = position; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    // Display the updated array
    cout << "Updated Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
