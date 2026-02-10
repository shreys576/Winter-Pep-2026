#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> vect;
        string fin = "";
        string str = "";
        for (char c: s) {
            if (c == ' ') {
                if (!str.empty()) { vect.push_back(str); str.clear(); }
            } else str += c;
        }
        if (!str.empty()) vect.push_back(str);
        if (vect.empty()) return "";
        for (int i = vect.size() - 1; i > 0; --i) {
            fin += vect[i]; fin += ' ';
        }
        fin += vect[0];
        return fin;
    }
};

int main() {
    Solution sol;
    cout << '"' << sol.reverseWords("  hello world  ") << '"' << "\n";
    cout << '"' << sol.reverseWords("a good   example") << '"' << "\n";
    return 0;
}
