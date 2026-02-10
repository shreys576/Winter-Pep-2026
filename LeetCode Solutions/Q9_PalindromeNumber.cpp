#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string p = s;
        int l = 0, r = p.length() - 1;
        while (l < r) swap(p[l++], p[r--]);
        return p == s;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "121 is palindrome? " << sol.isPalindrome(121) << "\n";
    cout << "-121 is palindrome? " << sol.isPalindrome(-121) << "\n";
    return 0;
}
