#include<bits/stdc++.h>
using namespace std;


int remove_duplicates(vector<int> &arr){

    int i = 0;
    for(int j = 1; j < arr.size(); j++){
        if(arr[i] != arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i + 1;
}


int main(){
    vector<int> arr = {1,1,2,2,2,3,4,4};
    int k = remove_duplicates(arr);
    cout << k;

}