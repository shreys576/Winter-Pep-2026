#include<bits/stdc++.h>
using namespace std;

string removeduplicates(string &s){
    string str = "";
    for(int i = 0; i< s.length(); i++){
        bool occur = false;
        for(int j = 0; j < str.length(); j++){
            if(s[i] == str[j]){
                occur = true;
            }
        }
        if(occur == false){
            str += s[i];
        }
    }
    return str;
}



int main(){

    string str = "banana";
    cout << removeduplicates(str);
}