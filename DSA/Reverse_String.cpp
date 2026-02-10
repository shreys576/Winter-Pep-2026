#include<bits/stdc++.h>
using namespace std;


int main(){

    string str = {"hello"};
    int s = 0;
    int l = str.length() - 1;
    while(s<l){
        swap(str[s], str[l]);
        s++;
        l--;
    }
    cout << str;
    
}