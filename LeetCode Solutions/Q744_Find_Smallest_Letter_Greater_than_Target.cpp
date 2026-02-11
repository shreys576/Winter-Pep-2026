#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char fin = letters[0];
        int mini = INT_MAX;
        for(auto i : letters){
            if(i - target > 0){
                if(i - target < mini){
                    fin = i;
                    mini = i - target;
                }
            }
        }
        return fin;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    vector<char> letters1 = {'c','f','j'};
    char target1 = 'a';
    cout << "letters = {c, f, j}, target = " << target1 << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters1, target1) 
         << " (Expected: c)\n\n";

    cout << "===== Test Case 2 =====\n";
    vector<char> letters2 = {'c','f','j'};
    char target2 = 'c';
    cout << "letters = {c, f, j}, target = " << target2 << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters2, target2) 
         << " (Expected: f)\n\n";

    cout << "===== Test Case 3 =====\n";
    vector<char> letters3 = {'c','f','j'};
    char target3 = 'd';
    cout << "letters = {c, f, j}, target = " << target3 << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters3, target3) 
         << " (Expected: f)\n\n";

    cout << "===== Test Case 4 (Wrap Around) =====\n";
    vector<char> letters4 = {'c','f','j'};
    char target4 = 'j';
    cout << "letters = {c, f, j}, target = " << target4 << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters4, target4) 
         << " (Expected: c)\n\n";

    cout << "===== Test Case 5 =====\n";
    vector<char> letters5 = {'x','x','y','y'};
    char target5 = 'z';
    cout << "letters = {x, x, y, y}, target = " << target5 << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters5, target5) 
         << " (Expected: x)\n\n";

    cout << "===== Test Case 6 =====\n";
    vector<char> letters6 = {'a','b','c'};
    char target6 = 'b';
    cout << "letters = {a, b, c}, target = " << target6 << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters6, target6) 
         << " (Expected: c)\n\n";

    return 0;
}
