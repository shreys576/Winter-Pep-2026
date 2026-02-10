#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            freq1[s[i] - 'a']++;
            freq2[t[i] - 'a']++;
        }
        return freq1 == freq2;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "anagram vs nagaram: " << sol.isAnagram("anagram", "nagaram") << "\n";
    cout << "rat vs car: " << sol.isAnagram("rat", "car") << "\n";
    return 0;
}
