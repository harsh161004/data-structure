#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "String: ";
    cin >> s;

    int left=0, right=s.length() - 1;
    bool isPalindrome = true;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = false;
            break;
        }
        left++; right--;
    }

    if (isPalindrome) {
        cout << "Its a palindrome." << endl;
    } else {
        cout << "Its NOT a palindrome." << endl;
    }

    return 0;
}
