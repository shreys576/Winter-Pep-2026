#include<bits/stdc++.h>
using namespace std;


int FindSum(int arr[], int size){
    if(size == 0) return 0;
    return arr[0] + FindSum(arr + 1, size - 1);
}

int main(){

    int arr[5] = {1,2,3,4,5};
    cout << FindSum(arr, 5);

}