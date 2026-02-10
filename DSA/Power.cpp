#include<bits/stdc++.h>
using namespace std;


int Power(int x, int n){
    if(n<=0) return 1;
    return x * Power(x, n - 1);
}


int main(){

    cout << Power(2, 5);

}