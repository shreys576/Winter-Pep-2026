#include<bits/stdc++.h>
using namespace std;

void move_zeroes(vector<int> &arr){
    int i = 0;
    for(int j = 1; j < arr.size(); j++){
        if(arr[j] != 0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
}

void print(vector<int> arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}


int main(){

    vector<int> arr = {0,1,0,3,12};
    move_zeroes(arr);
    print(arr);
}