#include<bits/stdc++.h>
using namespace std;
void SelectionSort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i ++){
        int smallest = i;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        swap(arr[i],arr[smallest]);

    }
}

void print(vector<int> arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {11,5,7,2,3};
    SelectionSort(arr);
    print(arr);
}