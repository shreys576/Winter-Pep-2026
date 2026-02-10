#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0}; int m = 3;
    vector<int> nums2 = {2,5,6}; int n = 3;
    sol.merge(nums1, m, nums2, n);
    cout << "Merged: "; for (int x: nums1) cout << x << " "; cout << "\n";
    return 0;
}
