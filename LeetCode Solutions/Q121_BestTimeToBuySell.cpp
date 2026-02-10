#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = prices[0];
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minbuy) minbuy = prices[i];
            else maxprofit = max(maxprofit, prices[i] - minbuy);
        }
        return maxprofit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Max profit: " << sol.maxProfit(prices) << "\n";
    return 0;
}
