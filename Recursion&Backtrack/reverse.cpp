#include <iostream>
using namespace std;

string reverseString(string s) {
    // Base case: empty string or single char
    if (s.length() <= 1)
        return s;
    // Recursive case: reverse substring from index 1 onwards, then add first char
    return reverseString(s.substr(1)) + s[0];
}

//inplace
void reverseString(string &s, int left, int right) {
    // Base case: stop when pointers meet or cross
    if (left >= right) return;

    // Swap characters at left and right
    swap(s[left], s[right]);

    // Recursive call moving inward
    reverseString(s, left + 1, right - 1);
}

int main() {
    string str = "hello";
    cout << reverseString(str) << endl; // Output: olleh
    return 0;
}
