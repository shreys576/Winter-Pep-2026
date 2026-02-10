#include<bits/stdc++.h>
using namespace std;

bool BinarySearch(int arr[], int key, int left, int right){
    if(left > right) return false;
    int mid = (left + right)/2;
    if(arr[mid] == key) return true;
    if(arr[mid] < key){
        BinarySearch(arr, key, mid + 1, right);
    }
    else{
        BinarySearch(arr, key, left, mid - 1);
    }

}


bool BinarySearchDiff(int arr[], int key, int size){
    int l = 0;
    int r = size - 1;
    int mid = (l+r)/2;
    if(arr[mid] == key) return true;
    if(r <= 1) return false;
    if(arr[mid] < key){
        BinarySearchDiff(arr + mid + 1, key, size);
    }
    else{
        BinarySearchDiff(arr, key, size - mid);
    }

}



int main(){

    int arr[] = {3,5,7,8,9,12,14,17,20,22};
    cout << BinarySearch(arr, 20, 0, 9) << endl;
    cout << BinarySearchDiff(arr, 3, 10);

}