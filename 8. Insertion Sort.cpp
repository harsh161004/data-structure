#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i=1; i<size; i++) {
        int key = arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[] = {33, 11, 22, 55, 44};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, size);

    cout << "After Insertion Sort: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
