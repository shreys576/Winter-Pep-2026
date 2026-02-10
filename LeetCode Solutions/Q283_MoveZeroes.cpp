#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) { swap(nums[i], nums[j]); j++; }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    cout << "After move: "; for (int x : nums) cout << x << " "; cout << "\n";
    return 0;
}
