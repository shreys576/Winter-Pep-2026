#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> fin;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s == 0) { fin.insert({nums[i], nums[j], nums[k]}); j++; k--; }
                else if (s < 0) j++; else k--;
            }
        }
        return vector<vector<int>>(fin.begin(), fin.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = sol.threeSum(nums);
    cout << "Triplets:\n";
    for (auto &v : res) {
        cout << "[";
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << (i + 1 == v.size() ? "" : ", ");
        }
        cout << "]\n";
    }
    return 0;
}
