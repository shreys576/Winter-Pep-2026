#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
vector<int> check;
    StockSpanner() {

    }
    
    int next(int price) {
        check.push_back(price);
        int count = 0;
        int i = check.size() - 1;
        while(i >= 0 && check[i] <= price){
            count++;
            i--;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    StockSpanner sp;

    cout << "===== Test Case 1 (LeetCode Standard Example) =====\n";
    vector<int> prices1 = {100, 80, 60, 70, 60, 75, 85};

    cout << "Prices: ";
    for(int p : prices1) cout << p << " ";
    cout << "\n\nSpans Output:\n";

    for(int p : prices1) {
        cout << "next(" << p << ") = " << sp.next(p) << endl;
    }

    cout << "Expected Output: 1 1 1 2 1 4 6\n\n";


    cout << "===== Test Case 2 =====\n";
    StockSpanner sp2;
    vector<int> prices2 = {10, 20, 30, 40, 50};

    cout << "Prices: ";
    for(int p : prices2) cout << p << " ";
    cout << "\n\nSpans Output:\n";

    for(int p : prices2) {
        cout << "next(" << p << ") = " << sp2.next(p) << endl;
    }

    cout << "Expected Output: 1 2 3 4 5\n\n";


    cout << "===== Test Case 3 (Decreasing Prices) =====\n";
    StockSpanner sp3;
    vector<int> prices3 = {50, 40, 30, 20, 10};

    cout << "Prices: ";
    for(int p : prices3) cout << p << " ";
    cout << "\n\nSpans Output:\n";

    for(int p : prices3) {
        cout << "next(" << p << ") = " << sp3.next(p) << endl;
    }

    cout << "Expected Output: 1 1 1 1 1\n\n";


    cout << "===== Test Case 4 (Same Prices) =====\n";
    StockSpanner sp4;
    vector<int> prices4 = {25, 25, 25, 25};

    cout << "Prices: ";
    for(int p : prices4) cout << p << " ";
    cout << "\n\nSpans Output:\n";

    for(int p : prices4) {
        cout << "next(" << p << ") = " << sp4.next(p) << endl;
    }

    cout << "Expected Output: 1 2 3 4\n\n";

    return 0;
}
