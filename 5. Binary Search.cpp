#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n-1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
        
    }
    return -1; // Not Found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key;

    cout << "Key: ";
    cin >> key;

    int result = binarySearch(arr, 5, key);

    switch (result) {
        case -1:
            cout << "Key not found" << endl;
            break;
        default:
            cout << "Key found at index " << result << endl;
    }

    return 0;
}
