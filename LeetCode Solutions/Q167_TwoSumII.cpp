#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) i++;
            else if (sum > target) j--;
            else return {i + 1, j + 1};
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    auto res = sol.twoSum(numbers, 9);
    cout << "1-based indices: " << res[0] << ", " << res[1] << "\n";
    return 0;
}
