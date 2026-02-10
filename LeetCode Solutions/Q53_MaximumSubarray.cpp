#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = 0;
        int maxsum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            currentsum += nums[i];
            maxsum = max(maxsum, currentsum);
            currentsum = (currentsum < 0) ? 0 : currentsum;
        }
        return maxsum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << sol.maxSubArray(nums) << "\n";
    return 0;
}
