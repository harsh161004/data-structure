#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {33, 11, 22, 55, 44};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, size);

    cout << "After Bubble Sort: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
