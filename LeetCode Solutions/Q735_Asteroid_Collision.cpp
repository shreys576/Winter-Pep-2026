#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int a : asteroids) {
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && a < 0) {
                if(st.top() < -a) {
                    st.pop();
                    continue;
                }
                else if(st.top() == -a) {
                    st.pop();
                }
                destroyed = true;
                break;
            }

            if(!destroyed) st.push(a);
        }

        vector<int> fin(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            fin[i] = st.top();
            st.pop();
        }

        return fin;
    }
};

// Helper function to print vector
void printVector(vector<int> v) {
    cout << "[ ";
    for(int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    vector<int> ast1 = {5, 10, -5};
    cout << "Input: ";
    printVector(ast1);

    vector<int> ans1 = sol.asteroidCollision(ast1);
    cout << "Output: ";
    printVector(ans1);
    cout << "Expected: [ 5 10 ]\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> ast2 = {8, -8};
    cout << "Input: ";
    printVector(ast2);

    vector<int> ans2 = sol.asteroidCollision(ast2);
    cout << "Output: ";
    printVector(ans2);
    cout << "Expected: [ ]\n\n";


    cout << "===== Test Case 3 =====\n";
    vector<int> ast3 = {10, 2, -5};
    cout << "Input: ";
    printVector(ast3);

    vector<int> ans3 = sol.asteroidCollision(ast3);
    cout << "Output: ";
    printVector(ans3);
    cout << "Expected: [ 10 ]\n\n";


    cout << "===== Test Case 4 =====\n";
    vector<int> ast4 = {-2, -1, 1, 2};
    cout << "Input: ";
    printVector(ast4);

    vector<int> ans4 = sol.asteroidCollision(ast4);
    cout << "Output: ";
    printVector(ans4);
    cout << "Expected: [ -2 -1 1 2 ]\n\n";


    cout << "===== Test Case 5 =====\n";
    vector<int> ast5 = {1, -2, -2, -2};
    cout << "Input: ";
    printVector(ast5);

    vector<int> ans5 = sol.asteroidCollision(ast5);
    cout << "Output: ";
    printVector(ans5);
    cout << "Expected: [ -2 -2 -2 ]\n\n";


    cout << "===== Test Case 6 =====\n";
    vector<int> ast6 = {3, 5, -7};
    cout << "Input: ";
    printVector(ast6);

    vector<int> ans6 = sol.asteroidCollision(ast6);
    cout << "Output: ";
    printVector(ans6);
    cout << "Expected: [ -7 ]\n\n";


    cout << "===== Test Case 7 =====\n";
    vector<int> ast7 = {4, 3, 2, 1, -10};
    cout << "Input: ";
    printVector(ast7);

    vector<int> ans7 = sol.asteroidCollision(ast7);
    cout << "Output: ";
    printVector(ans7);
    cout << "Expected: [ -10 ]\n\n";

    return 0;
}
