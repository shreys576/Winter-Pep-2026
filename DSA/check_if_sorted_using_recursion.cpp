#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size){
    if(size <= 1) return true;
    if(arr[0] > arr[1]) return false;
    isSorted(arr + 1, size - 1);
}

int main(){
    int arr[6] = {2, 3, 5, 7, 8, 11};
    cout << isSorted(arr,6);
}