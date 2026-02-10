#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                int l = mid, r = mid;
                while (l >= 0 && nums[l] == target) l--;
                while (r < nums.size() && nums[r] == target) r++;
                return {l + 1, r - 1};
            } else if (nums[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto res = sol.searchRange(nums, 8);
    cout << "Range: " << res[0] << ", " << res[1] << "\n";
    return 0;
}
