#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        stack<int> st;
        for(int i = 0; i < 32; i++){
            st.push(n & 1);
            n = n >> 1;
        }

        int i = 0;
        int fin = 0;
        while(!st.empty()){
            fin += pow(2,i)* st.top();
            st.pop();
            i++;
        }
        return fin;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    int n1 = 43261596;  
    cout << "Input: " << n1 << endl;
    cout << "Output: " << sol.reverseBits(n1) << endl;
    cout << "Expected: 964176192\n\n";


    cout << "===== Test Case 2 =====\n";
    int n2 = 0;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << sol.reverseBits(n2) << endl;
    cout << "Expected: 0\n\n";


    cout << "===== Test Case 3 =====\n";
    int n3 = 1;
    cout << "Input: " << n3 << endl;
    cout << "Output: " << sol.reverseBits(n3) << endl;
    cout << "Expected: 2147483648 (BUT will overflow int)\n\n";


    cout << "===== Test Case 4 =====\n";
    int n4 = 2147483647; // max int
    cout << "Input: " << n4 << endl;
    cout << "Output: " << sol.reverseBits(n4) << endl;
    cout << "Expected: depends on 32-bit reversal\n\n";

    return 0;
}
