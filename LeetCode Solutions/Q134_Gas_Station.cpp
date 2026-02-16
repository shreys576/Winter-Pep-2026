#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg = 0;
        int sumc = 0;
        for(int i = 0; i < gas.size(); i++){
            sumg += gas[i];
            sumc += cost[i];
        }
        if(sumg < sumc) return -1;

        int balance = 0;
        int total = 0;
        int curr = 0;
        int start = 0;
        for(int i =0; i < gas.size(); i++){
            balance = gas[i] - cost[i];
            total += balance;
            curr += balance;

            if(curr < 0){
                start = i + 1;
                curr = 0;
            }
        }

        if(total < 0) return -1;
        return start;
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
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};

    cout << "Gas  = ";
    printVector(gas1);
    cout << "Cost = ";
    printVector(cost1);

    cout << "Output: " << sol.canCompleteCircuit(gas1, cost1)
         << " (Expected: 3)\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};

    cout << "Gas  = ";
    printVector(gas2);
    cout << "Cost = ";
    printVector(cost2);

    cout << "Output: " << sol.canCompleteCircuit(gas2, cost2)
         << " (Expected: -1)\n\n";


    cout << "===== Test Case 3 =====\n";
    vector<int> gas3 = {5, 1, 2, 3, 4};
    vector<int> cost3 = {4, 4, 1, 5, 1};

    cout << "Gas  = ";
    printVector(gas3);
    cout << "Cost = ";
    printVector(cost3);

    cout << "Output: " << sol.canCompleteCircuit(gas3, cost3)
         << " (Expected: 4)\n\n";


    cout << "===== Test Case 4 (Single Station) =====\n";
    vector<int> gas4 = {5};
    vector<int> cost4 = {4};

    cout << "Gas  = ";
    printVector(gas4);
    cout << "Cost = ";
    printVector(cost4);

    cout << "Output: " << sol.canCompleteCircuit(gas4, cost4)
         << " (Expected: 0)\n\n";


    cout << "===== Test Case 5 (Exact Balance) =====\n";
    vector<int> gas5 = {2, 2, 2};
    vector<int> cost5 = {2, 2, 2};

    cout << "Gas  = ";
    printVector(gas5);
    cout << "Cost = ";
    printVector(cost5);

    cout << "Output: " << sol.canCompleteCircuit(gas5, cost5)
         << " (Expected: 0)\n\n";


    cout << "===== Test Case 6 =====\n";
    vector<int> gas6 = {3, 3, 4};
    vector<int> cost6 = {3, 4, 4};

    cout << "Gas  = ";
    printVector(gas6);
    cout << "Cost = ";
    printVector(cost6);

    cout << "Output: " << sol.canCompleteCircuit(gas6, cost6)
         << " (Expected: -1)\n\n";

    return 0;
}
