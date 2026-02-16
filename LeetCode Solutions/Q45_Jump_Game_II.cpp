#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int end = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if(i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
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
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Input: ";
    printVector(nums1);
    cout << "Output: " << sol.jump(nums1) << " (Expected: 2)\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Input: ";
    printVector(nums2);
    cout << "Output: " << sol.jump(nums2) << " (Expected: 2)\n\n";


    cout << "===== Test Case 3 =====\n";
    vector<int> nums3 = {1, 1, 1, 1, 1};
    cout << "Input: ";
    printVector(nums3);
    cout << "Output: " << sol.jump(nums3) << " (Expected: 4)\n\n";


    cout << "===== Test Case 4 (Single element) =====\n";
    vector<int> nums4 = {0};
    cout << "Input: ";
    printVector(nums4);
    cout << "Output: " << sol.jump(nums4) << " (Expected: 0)\n\n";


    cout << "===== Test Case 5 =====\n";
    vector<int> nums5 = {3, 2, 1};
    cout << "Input: ";
    printVector(nums5);
    cout << "Output: " << sol.jump(nums5) << " (Expected: 1)\n\n";


    cout << "===== Test Case 6 =====\n";
    vector<int> nums6 = {1, 2, 3};
    cout << "Input: ";
    printVector(nums6);
    cout << "Output: " << sol.jump(nums6) << " (Expected: 2)\n\n";


    cout << "===== Test Case 7 =====\n";
    vector<int> nums7 = {4, 1, 1, 3, 1, 1, 1};
    cout << "Input: ";
    printVector(nums7);
    cout << "Output: " << sol.jump(nums7) << " (Expected: 2)\n\n";

    return 0;
}
