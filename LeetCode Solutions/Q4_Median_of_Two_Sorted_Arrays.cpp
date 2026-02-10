#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size();
        int j = nums2.size();
        int k = i + j;
        vector<int> fin(k, 0);
        i--;
        j--;
        k--;
        while(j >= 0 && i >= 0){
            if(nums1[i] > nums2[j]){
                fin[k--] = nums1[i--];
            }
            else{
                fin[k--] = nums2[j--];
            }
        }
        while(j>=0) fin[k--] = nums2[j--];
        while(i>=0) fin[k--] = nums1[i--];
        double median;
        if(fin.size()%2!=0){
            int index = fin.size()/2;
            median = fin[index];
        }
        else{
            int index = fin.size()/2;
            median = (fin[index] + fin[index - 1])/2.0;
        }
        return median;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "nums1 = {1, 3}, nums2 = {2}\n";
    cout << "Median = " << sol.findMedianSortedArrays(nums1, nums2) 
         << " (Expected: 2.0)\n\n";

    cout << "===== Test Case 2 =====\n";
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "nums1 = {1, 2}, nums2 = {3, 4}\n";
    cout << "Median = " << sol.findMedianSortedArrays(nums3, nums4) 
         << " (Expected: 2.5)\n\n";

    cout << "===== Test Case 3 =====\n";
    vector<int> nums5 = {0, 0};
    vector<int> nums6 = {0, 0};
    cout << "nums1 = {0, 0}, nums2 = {0, 0}\n";
    cout << "Median = " << sol.findMedianSortedArrays(nums5, nums6) 
         << " (Expected: 0.0)\n\n";

    cout << "===== Test Case 4 =====\n";
    vector<int> nums7 = {};
    vector<int> nums8 = {1};
    cout << "nums1 = {}, nums2 = {1}\n";
    cout << "Median = " << sol.findMedianSortedArrays(nums7, nums8) 
         << " (Expected: 1.0)\n\n";

    cout << "===== Test Case 5 =====\n";
    vector<int> nums9 = {2};
    vector<int> nums10 = {};
    cout << "nums1 = {2}, nums2 = {}\n";
    cout << "Median = " << sol.findMedianSortedArrays(nums9, nums10) 
         << " (Expected: 2.0)\n\n";

    cout << "===== Test Case 6 =====\n";
    vector<int> nums11 = {1, 4, 7, 10};
    vector<int> nums12 = {2, 3, 6, 9, 11};
    cout << "nums1 = {1, 4, 7, 10}, nums2 = {2, 3, 6, 9, 11}\n";
    cout << "Median = " << sol.findMedianSortedArrays(nums11, nums12) 
         << " (Expected: 6.0)\n\n";

    return 0;
}
