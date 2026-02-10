#include<bits/stdc++.h>
using namespace std;

void print(int n, int r){
    if(n <= r){
        if(n%2 == 0){
            cout << n << endl;
        }
    }
    print(++n, r);
}


int main(){

    print(1, 100);

}