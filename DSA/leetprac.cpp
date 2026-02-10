#include<bits/stdc++.h>
using namespace std;

void fun(vector<int> &arr){
    for(int i = 0; i< arr.size(); i++){
        if(arr[i] == 0){
            for(int j = i; j<arr.size() - 1; j++){
                swap(arr[j],arr[j + 1]);
            }
            i--;
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
    vector<int> arr = {0, 1, 0, 3, 12};
    fun(arr);
    print(arr);

}