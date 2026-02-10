#include<bits/stdc++.h>
using namespace std;

void print10(int &n){
    while(n <= 10){
        cout << n++ << endl;
        print10(n);
    }
}


int main(){
    int n = 1;
    print10(n);

}