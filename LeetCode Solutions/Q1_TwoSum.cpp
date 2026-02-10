#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                if (sum == target) return {i, j};
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto res = sol.twoSum(nums, target);
    cout << "Indices: " << res[0] << ", " << res[1] << "\n";
    return 0;
}
