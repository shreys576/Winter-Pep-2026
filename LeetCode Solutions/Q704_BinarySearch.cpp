#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    cout << "Index of 9: " << sol.search(nums, 9) << "\n";
    cout << "Index of 2: " << sol.search(nums, 2) << "\n";
    return 0;
}
