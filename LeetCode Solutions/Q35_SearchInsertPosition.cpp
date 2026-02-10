#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) e = mid - 1;
            else s = mid + 1;
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    cout << "Insert position for 5: " << sol.searchInsert(nums, 5) << "\n";
    cout << "Insert position for 2: " << sol.searchInsert(nums, 2) << "\n";
    return 0;
}
