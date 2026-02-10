#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr){
    for(int i = 0; i< arr.size(); i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j],arr[j+1]);
            }
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
    vector<int> arr = {7, 2, 5, 3, 1};
    BubbleSort(arr);
    print(arr);
}