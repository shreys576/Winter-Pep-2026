#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        int ans = INT_MAX;

        for(int r = 0; r < n; r++) {
            sum += nums[r];  // expand window

            while(sum >= target) {
                ans = min(ans, r - l + 1); // update min length
                sum -= nums[l]; // shrink window
                l++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

// Helper function to print vector
void printVector(vector<int> v) {
    cout << "[ ";
    for(int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    int target1 = 7;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << "Target = " << target1 << endl;
    cout << "Nums   = ";
    printVector(nums1);

    cout << "Output: " << sol.minSubArrayLen(target1, nums1)
         << " (Expected: 2)\n\n";


    cout << "===== Test Case 2 =====\n";
    int target2 = 4;
    vector<int> nums2 = {1, 4, 4};
    cout << "Target = " << target2 << endl;
    cout << "Nums   = ";
    printVector(nums2);

    cout << "Output: " << sol.minSubArrayLen(target2, nums2)
         << " (Expected: 1)\n\n";


    cout << "===== Test Case 3 =====\n";
    int target3 = 11;
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Target = " << target3 << endl;
    cout << "Nums   = ";
    printVector(nums3);

    cout << "Output: " << sol.minSubArrayLen(target3, nums3)
         << " (Expected: 0)\n\n";


    cout << "===== Test Case 4 =====\n";
    int target4 = 15;
    vector<int> nums4 = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    cout << "Target = " << target4 << endl;
    cout << "Nums   = ";
    printVector(nums4);

    cout << "Output: " << sol.minSubArrayLen(target4, nums4)
         << " (Expected: 2)\n\n";


    cout << "===== Test Case 5 (Single Element Works) =====\n";
    int target5 = 3;
    vector<int> nums5 = {3};
    cout << "Target = " << target5 << endl;
    cout << "Nums   = ";
    printVector(nums5);

    cout << "Output: " << sol.minSubArrayLen(target5, nums5)
         << " (Expected: 1)\n\n";


    cout << "===== Test Case 6 (Single Element Fails) =====\n";
    int target6 = 10;
    vector<int> nums6 = {5};
    cout << "Target = " << target6 << endl;
    cout << "Nums   = ";
    printVector(nums6);

    cout << "Output: " << sol.minSubArrayLen(target6, nums6)
         << " (Expected: 0)\n\n";


    cout << "===== Test Case 7 (Exact Match Whole Array) =====\n";
    int target7 = 6;
    vector<int> nums7 = {1, 2, 3};
    cout << "Target = " << target7 << endl;
    cout << "Nums   = ";
    printVector(nums7);

    cout << "Output: " << sol.minSubArrayLen(target7, nums7)
         << " (Expected: 3)\n\n";

    return 0;
}
