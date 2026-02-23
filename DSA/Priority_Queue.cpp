#include<bits/stdc++.h>
using namespace std;


int main(){

    // Max Heap
    priority_queue<int> pq_max;

    //Min Heap
    priority_queue<int, vector<int>, greater<int>> pq_min;

    pq_max.push(10);
    pq_max.push(5);
    pq_max.push(50);
    pq_max.push(20);

    cout << pq_max.size() << endl;

    while(!pq_max.empty()){
        cout << pq_max.top() << " ";
        pq_max.pop();
    }
    cout << endl;

    

}