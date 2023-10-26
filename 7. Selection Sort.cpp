#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i=0; i<size-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

    selectionSort(arr, size);

    cout << "Selection Sort: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
