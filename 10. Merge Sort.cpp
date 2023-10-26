#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;

    int leftArr[n1], rightArr[n2];

    for (int i=0; i<n1; i++)
        leftArr[i] = arr[left + i];
    for (int j=0; j<n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i=0, j=0, k=left;

    while (i<n1 && j<n2) {
        if (leftArr[i] <= rightArr[j]) arr[k] = leftArr[i++];
        else arr[k] = rightArr[j++];
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right-left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {33, 11, 22, 55, 44};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "After Merge Sort: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
