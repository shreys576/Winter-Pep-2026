#include<bits/stdc++.h>
using namespace std;


int main(){

    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int max_sum = 0;
    int index = 0;

    for(int i = 0; i < 4; i ++){
        int sum = 0;
        for(int j = 0; j < 3; j++){
            sum += arr[j][i];
        }
        if(max_sum < sum){
            max_sum = sum;
            index = i;
        }
    }
    cout << index;

}