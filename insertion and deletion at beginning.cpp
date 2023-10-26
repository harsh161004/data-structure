#include <iostream>
using namespace std;

int main() {
    int array[100];
    int size, element;

    // Input array size
    cout << "Enter the size of the array: ";
    cin >> size;

    // Input array elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Element to insert at the beginning
    cout << "Enter the element to insert at the beginning: ";
    cin >> element;

    // Shift elements to make space for the new element
    for (int i = size; i >= 1; i--) {
        array[i] = array[i - 1];
    }

    // Insert the element at the beginning
    array[0] = element;
    size++;

    // Display the updated array
    cout << "Updated Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
