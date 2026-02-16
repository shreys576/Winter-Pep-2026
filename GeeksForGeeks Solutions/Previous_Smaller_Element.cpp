#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            
            if(!st.empty()) ans[i] = st.top();
            
            st.push(arr[i]);
        }
        
        return ans;
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
    vector<int> arr1 = {4, 5, 2, 10, 8};
    cout << "Input: ";
    printVector(arr1);

    vector<int> ans1 = sol.prevSmaller(arr1);
    cout << "Output: ";
    printVector(ans1);
    cout << "Expected: [ -1 4 -1 2 2 ]\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> arr2 = {3, 2, 1};
    cout << "Input: ";
    printVector(arr2);

    vector<int> ans2 = sol.prevSmaller(arr2);
    cout << "Output: ";
    printVector(ans2);
    cout << "Expected: [ -1 -1 -1 ]\n\n";


    cout << "===== Test Case 3 =====\n";
    vector<int> arr3 = {1, 2, 3, 4};
    cout << "Input: ";
    printVector(arr3);

    vector<int> ans3 = sol.prevSmaller(arr3);
    cout << "Output: ";
    printVector(ans3);
    cout << "Expected: [ -1 1 2 3 ]\n\n";


    cout << "===== Test Case 4 (Duplicates) =====\n";
    vector<int> arr4 = {2, 2, 2, 2};
    cout << "Input: ";
    printVector(arr4);

    vector<int> ans4 = sol.prevSmaller(arr4);
    cout << "Output: ";
    printVector(ans4);
    cout << "Expected: [ -1 -1 -1 -1 ]\n\n";


    cout << "===== Test Case 5 =====\n";
    vector<int> arr5 = {8, 7, 6, 5, 4};
    cout << "Input: ";
    printVector(arr5);

    vector<int> ans5 = sol.prevSmaller(arr5);
    cout << "Output: ";
    printVector(ans5);
    cout << "Expected: [ -1 -1 -1 -1 -1 ]\n\n";


    cout << "===== Test Case 6 (Single Element) =====\n";
    vector<int> arr6 = {10};
    cout << "Input: ";
    printVector(arr6);

    vector<int> ans6 = sol.prevSmaller(arr6);
    cout << "Output: ";
    printVector(ans6);
    cout << "Expected: [ -1 ]\n\n";

    return 0;
}
