#include<bits/stdc++.h>
using namespace std;

bool search(int arr[], int size, int key){
    if(size == 0) return false;
    if(arr[0] == key) return true;
    search(arr + 1, size - 1, key);
}

int searchIndex(int arr[], int size, int key){
    if(size == 0) return -1;
    if(arr[0] == key) return size;
    search(arr + 1, size - 1, key);
}


int main(){

    int arr[] = {1,2,3,4,5};
    cout << search(arr, 5, 2) << endl;

}