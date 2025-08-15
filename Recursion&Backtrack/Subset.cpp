#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getSubsets2(vector<int>& nums, vector<vector<int>>& allSubsets, vector<int>& tempsubset, int index) {
        // base case
        if (index == nums.size()) {
            allSubsets.push_back(tempsubset);
            return;
        }

        // INCLUDE current element
        tempsubset.push_back(nums[index]);
        getSubsets2(nums, allSubsets, tempsubset, index + 1);
        tempsubset.pop_back();

        // SKIP duplicates before exploring exclude path
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }

        // EXCLUDE current element
        getSubsets2(nums, allSubsets, tempsubset, index + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> tempsubset;
        sort(nums.begin(), nums.end());
        getSubsets2(nums, allSubsets, tempsubset, 0);
        return allSubsets;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2, 3};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Unique subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
