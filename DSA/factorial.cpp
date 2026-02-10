#include<bits/stdc++.h>
using namespace std;

int Factorial(int n){
    if(n <= 1) return 1;
    return n * Factorial(n - 1);
}

int Power(int x, int n){
    if(n<=0) return 1;
    return x * Power(x, n - 1);
}


int main(){

    cout << Factorial(5) << endl;
    cout << Power(2, 5);

}