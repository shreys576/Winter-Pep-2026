#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, currentcount = 0, maxcount = 0;
        while (i < nums.size()) {
            if (nums[i] == 1) currentcount++;
            else { maxcount = max(maxcount, currentcount); currentcount = 0; }
            i++;
        }
        return max(maxcount, currentcount);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,0,1,1,1};
    cout << "Max consecutive ones: " << sol.findMaxConsecutiveOnes(nums) << "\n";
    return 0;
}
