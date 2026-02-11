#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen = 0;
        int curr = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            set<int> even;
            set<int> odd;
            for(int j = i; j <  nums.size(); j++){
                curr = j - i + 1;
                if(nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(odd.size() == even.size()) maxlen = max(maxlen, curr);
            }
        }
        return maxlen;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Input: {1, 2, 3, 4}\n";
    cout << "Output: " << sol.longestBalanced(nums1) << "\n";
    cout << "Expected: 4 (odd unique {1,3}, even unique {2,4})\n\n";

    cout << "===== Test Case 2 =====\n";
    vector<int> nums2 = {1, 1, 2, 2};
    cout << "Input: {1, 1, 2, 2}\n";
    cout << "Output: " << sol.longestBalanced(nums2) << "\n";
    cout << "Expected: 4 (odd unique {1}, even unique {2})\n\n";

    cout << "===== Test Case 3 =====\n";
    vector<int> nums3 = {1, 3, 5, 7};
    cout << "Input: {1, 3, 5, 7}\n";
    cout << "Output: " << sol.longestBalanced(nums3) << "\n";
    cout << "Expected: 0 (no evens at all)\n\n";

    cout << "===== Test Case 4 =====\n";
    vector<int> nums4 = {2, 4, 6, 8};
    cout << "Input: {2, 4, 6, 8}\n";
    cout << "Output: " << sol.longestBalanced(nums4) << "\n";
    cout << "Expected: 0 (no odds at all)\n\n";

    cout << "===== Test Case 5 =====\n";
    vector<int> nums5 = {1, 2, 2, 3, 4, 4, 5};
    cout << "Input: {1, 2, 2, 3, 4, 4, 5}\n";
    cout << "Output: " << sol.longestBalanced(nums5) << "\n";
    cout << "Expected: depends on unique odd/even counts, but should be >= 4\n\n";

    cout << "===== Test Case 6 (Small case) =====\n";
    vector<int> nums6 = {1, 2};
    cout << "Input: {1, 2}\n";
    cout << "Output: " << sol.longestBalanced(nums6) << "\n";
    cout << "Expected: 2\n\n";

    cout << "===== Test Case 7 (Single element) =====\n";
    vector<int> nums7 = {5};
    cout << "Input: {5}\n";
    cout << "Output: " << sol.longestBalanced(nums7) << "\n";
    cout << "Expected: 0\n\n";

    return 0;
}
