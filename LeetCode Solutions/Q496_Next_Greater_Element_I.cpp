#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> fin(nums2.size(), -1);

        for(int i = nums2.size() - 1; i >= 0; i--){
                while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty()) fin[i] = st.top();
            st.push(nums2[i]);
        }

        vector<int> fin2(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    fin2[i] = fin[j];
                }
            }
        }
        return fin2;
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
    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};

    cout << "nums1 = ";
    printVector(nums1_1);
    cout << "nums2 = ";
    printVector(nums2_1);

    vector<int> ans1 = sol.nextGreaterElement(nums1_1, nums2_1);

    cout << "Output = ";
    printVector(ans1);
    cout << "Expected: [ -1 3 -1 ]\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};

    cout << "nums1 = ";
    printVector(nums1_2);
    cout << "nums2 = ";
    printVector(nums2_2);

    vector<int> ans2 = sol.nextGreaterElement(nums1_2, nums2_2);

    cout << "Output = ";
    printVector(ans2);
    cout << "Expected: [ 3 -1 ]\n\n";


    cout << "===== Test Case 3 =====\n";
    vector<int> nums1_3 = {1, 3, 5, 2, 4};
    vector<int> nums2_3 = {6, 5, 4, 3, 2, 1, 7};

    cout << "nums1 = ";
    printVector(nums1_3);
    cout << "nums2 = ";
    printVector(nums2_3);

    vector<int> ans3 = sol.nextGreaterElement(nums1_3, nums2_3);

    cout << "Output = ";
    printVector(ans3);
    cout << "Expected: [ 7 7 7 7 7 ]\n\n";


    cout << "===== Test Case 4 (Single Element) =====\n";
    vector<int> nums1_4 = {1};
    vector<int> nums2_4 = {1, 2};

    cout << "nums1 = ";
    printVector(nums1_4);
    cout << "nums2 = ";
    printVector(nums2_4);

    vector<int> ans4 = sol.nextGreaterElement(nums1_4, nums2_4);

    cout << "Output = ";
    printVector(ans4);
    cout << "Expected: [ 2 ]\n\n";


    cout << "===== Test Case 5 (No Next Greater Exists) =====\n";
    vector<int> nums1_5 = {5};
    vector<int> nums2_5 = {5, 4, 3, 2, 1};

    cout << "nums1 = ";
    printVector(nums1_5);
    cout << "nums2 = ";
    printVector(nums2_5);

    vector<int> ans5 = sol.nextGreaterElement(nums1_5, nums2_5);

    cout << "Output = ";
    printVector(ans5);
    cout << "Expected: [ -1 ]\n\n";

    return 0;
}
