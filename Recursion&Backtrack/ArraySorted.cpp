#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &nums, int n)
{
    if (n == 0 || n == 1)
        return true;
    return (nums[n - 1] > nums[n - 2] && isSorted(nums, n - 1));
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 6,-1};
    int n = vec.size();
    bool ans = isSorted(vec, n);
    cout << ans;
    return 0;
}