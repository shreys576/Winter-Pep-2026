#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = 0;
        for (int x : piles) maxi = max(maxi, x);
        return maxi;
    }
    long long findTime(vector<int>& piles, int k) {
        long long time = 0;
        for (int x : piles) time += (x + k - 1) / k; // ceil
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = findMax(piles);
        int l = 1, ans = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            long long time = findTime(piles, mid);
            if (time <= h) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << "Min eating speed: " << sol.minEatingSpeed(piles, h) << "\n";
    return 0;
}
