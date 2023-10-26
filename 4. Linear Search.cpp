#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i=0; i<n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Not Found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key;

    cout << "Key: ";
    cin >> key;

    int result = linearSearch(arr, 5, key);

    switch (result) {
        case -1:
            cout << "Key not found in the array." << endl;
            break;
        default:
            cout << "Key found at index " << result << endl;
    }

    return 0;
}
