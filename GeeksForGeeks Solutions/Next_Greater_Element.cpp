#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;  // stores elements
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= arr[i]) {
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
    vector<int> arr1 = {1, 3, 2, 4};
    cout << "Input: ";
    printVector(arr1);

    vector<int> ans1 = sol.nextLargerElement(arr1);
    cout << "Output: ";
    printVector(ans1);
    cout << "Expected: [ 3 4 4 -1 ]\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> arr2 = {6, 8, 0, 1, 3};
    cout << "Input: ";
    printVector(arr2);

    vector<int> ans2 = sol.nextLargerElement(arr2);
    cout << "Output: ";
    printVector(ans2);
    cout << "Expected: [ 8 -1 1 3 -1 ]\n\n";


    cout << "===== Test Case 3 =====\n";
    vector<int> arr3 = {4, 3, 2, 1};
    cout << "Input: ";
    printVector(arr3);

    vector<int> ans3 = sol.nextLargerElement(arr3);
    cout << "Output: ";
    printVector(ans3);
    cout << "Expected: [ -1 -1 -1 -1 ]\n\n";


    cout << "===== Test Case 4 =====\n";
    vector<int> arr4 = {1, 2, 3, 4, 5};
    cout << "Input: ";
    printVector(arr4);

    vector<int> ans4 = sol.nextLargerElement(arr4);
    cout << "Output: ";
    printVector(ans4);
    cout << "Expected: [ 2 3 4 5 -1 ]\n\n";


    cout << "===== Test Case 5 (Duplicates) =====\n";
    vector<int> arr5 = {2, 2, 2, 3};
    cout << "Input: ";
    printVector(arr5);

    vector<int> ans5 = sol.nextLargerElement(arr5);
    cout << "Output: ";
    printVector(ans5);
    cout << "Expected: [ 3 3 3 -1 ]\n\n";


    cout << "===== Test Case 6 (Single Element) =====\n";
    vector<int> arr6 = {10};
    cout << "Input: ";
    printVector(arr6);

    vector<int> ans6 = sol.nextLargerElement(arr6);
    cout << "Output: ";
    printVector(ans6);
    cout << "Expected: [ -1 ]\n\n";

    return 0;
}
