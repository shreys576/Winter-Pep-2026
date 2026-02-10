#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        bool flag = false;
        for(auto i : s){
            if(i == '(' || i == '{' || i == '['){
                open.push(i);
            }
            else{
                if(open.empty()) return false;
                if((open.top() == '(' && i == ')') || (open.top() == '[' && i == ']') || (open.top() == '{' && i == '}')){
                    flag = true;
                }
                else{
                    return false;
                }
                open.pop();
            }
        }
        if(!open.empty()) return false;
        return flag;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    string s1 = "()";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.isValid(s1) << " (Expected: 1)\n\n";

    cout << "===== Test Case 2 =====\n";
    string s2 = "()[]{}";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.isValid(s2) << " (Expected: 1)\n\n";

    cout << "===== Test Case 3 =====\n";
    string s3 = "(]";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << sol.isValid(s3) << " (Expected: 0)\n\n";

    cout << "===== Test Case 4 =====\n";
    string s4 = "([)]";
    cout << "Input: " << s4 << endl;
    cout << "Output: " << sol.isValid(s4) << " (Expected: 0)\n\n";

    cout << "===== Test Case 5 =====\n";
    string s5 = "{[]}";
    cout << "Input: " << s5 << endl;
    cout << "Output: " << sol.isValid(s5) << " (Expected: 1)\n\n";

    cout << "===== Test Case 6 (Empty String) =====\n";
    string s6 = "";
    cout << "Input: \"" << s6 << "\"" << endl;
    cout << "Output: " << sol.isValid(s6) << " (Expected: 0)\n\n";

    cout << "===== Test Case 7 =====\n";
    string s7 = "((()))";
    cout << "Input: " << s7 << endl;
    cout << "Output: " << sol.isValid(s7) << " (Expected: 1)\n\n";

    cout << "===== Test Case 8 =====\n";
    string s8 = "(((";
    cout << "Input: " << s8 << endl;
    cout << "Output: " << sol.isValid(s8) << " (Expected: 0)\n\n";

    return 0;
}
