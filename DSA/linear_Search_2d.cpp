#include<bits/stdc++.h>
using namespace std;

bool Search(int arr[][4], int key, int n){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == key) return true;
        }
    }
    return false;
}


int main(){
    int arr[][4] = {1,7,14,6,11,15,5,10,2,4,16,3,8,13,8,12};
    cout << Search(arr, 9, 4);

}