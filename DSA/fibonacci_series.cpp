#include<bits/stdc++.h>
using namespace std;

void Fibonacci(int i, int j, int k){
    int temp = i;
    i = j;
    j += temp;
    if(j <= k){
        cout << j << endl;
        Fibonacci(i, j, k);
    }
}

int main(){
    int i = 0;
    int j = 1;
    cout << i << endl;
    cout << j << endl;
    Fibonacci(0,1,13);

}