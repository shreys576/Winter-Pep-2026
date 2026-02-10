#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) { swap(nums[i], nums[j]); i++; }
        }
        return i;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int k = sol.removeElement(nums, val);
    cout << "New length: " << k << "\nElements: ";
    for (int i = 0; i < k; ++i) cout << nums[i] << " ";
    cout << "\n";
    return 0;
}
