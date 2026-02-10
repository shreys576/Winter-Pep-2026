#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[mid] < nums[mid + 1]) s = mid + 1;
            else e = mid;
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak index: " << sol.findPeakElement(nums) << "\n";
    return 0;
}
