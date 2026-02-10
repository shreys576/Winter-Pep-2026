#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if (arr.empty()) return 0;
        int j = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[j] != arr[i]) { j++; swap(arr[j], arr[i]); }
        }
        return j + 1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2};
    int k = sol.removeDuplicates(arr);
    cout << "New length: " << k << "\nElements: ";
    for (int i = 0; i < k; ++i) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
