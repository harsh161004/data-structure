#include <iostream>
using namespace std;

int main() {
    int array[100];
    int size;

    // Input array size
    cout << "Enter the size of the array: ";
    cin >> size;

    // Input array elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Delete the element at the end
    if (size > 0) {  // Check for array underflow
        size--;
        // Display the updated array
        cout << "Updated Array: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Array is empty. Deletion not possible." << endl;
    }

    return 0;
}
