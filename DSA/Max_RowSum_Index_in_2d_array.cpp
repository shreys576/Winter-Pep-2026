#include<bits/stdc++.h>
using namespace std;


int main(){

    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int max_sum = 0;
    int index = -1;
    for(int i = 0;i<3;i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            sum += arr[i][j];
        }
        if(sum > max_sum){
            max_sum = sum;
            index = i;
        }
    }

    cout << index;


}