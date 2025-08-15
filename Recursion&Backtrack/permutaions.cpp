#include <bits/stdc++.h>
using namespace std;

void permute(string &s, int index, vector<string> &result) {
    // Base case: if we've fixed all positions
    if (index == s.size()) {
        result.push_back(s);
        return;
    }

    // Swap each possible choice into the current position
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);            // choose
        permute(s, index + 1, result);   // explore
        swap(s[index], s[i]);            // un-choose (backtrack)
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> result;
    permute(s, 0, result);

    cout << "\nAll permutations:\n";
    for (const string &p : result) {
        cout << p << "\n";
    }

    return 0;
}
