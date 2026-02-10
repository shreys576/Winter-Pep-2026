#include <bits/stdc++.h>
using namespace std;

int main() {
  
    // Initialize 2D vector of size 3 x 3 with
  	// default value 5
    vector<vector<int>> v(3, vector<int>(3, 5));

    for (auto i : v) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}