#include<bits/stdc++.h>
using namespace std;


vector<int> twosum(vector<int> &arr, int target){
    int i = 0;
    int j = arr.size() - 1;
    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum == target){
            return {i + 1, j + 1};
        }
        else if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }
    return {-1, -1};
}

void print(vector<int> arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){

    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> fin = twosum(arr, target);
    print(fin);

}