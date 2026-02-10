#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c: s) if (isalnum(c)) str.push_back(tolower(c));
        string p = str;
        int l = 0, r = p.length() - 1;
        while (l < r) swap(p[l++], p[r--]);
        return p == str;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << "\n";
    cout << sol.isPalindrome("race a car") << "\n";
    return 0;
}
