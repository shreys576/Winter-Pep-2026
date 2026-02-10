#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

void printVector(vector<char>& s) {
    for(char c : s) cout << c << " ";
    cout << endl;
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    vector<char> s1 = {'h','e','l','l','o'};
    cout << "Original: ";
    printVector(s1);

    sol.reverseString(s1);

    cout << "Reversed: ";
    printVector(s1);
    cout << "Expected: o l l e h\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<char> s2 = {'H','a','n','n','a','h'};
    cout << "Original: ";
    printVector(s2);

    sol.reverseString(s2);

    cout << "Reversed: ";
    printVector(s2);
    cout << "Expected: h a n n a H\n\n";


    cout << "===== Test Case 3 (Single Character) =====\n";
    vector<char> s3 = {'a'};
    cout << "Original: ";
    printVector(s3);

    sol.reverseString(s3);

    cout << "Reversed: ";
    printVector(s3);
    cout << "Expected: a\n\n";


    cout << "===== Test Case 4 (Empty Vector) =====\n";
    vector<char> s4 = {};
    cout << "Original: ";
    printVector(s4);

    sol.reverseString(s4);

    cout << "Reversed: ";
    printVector(s4);
    cout << "Expected: (empty)\n\n";

    return 0;
}
