#include<bits/stdc++.h>
using namespace std;


int binarysearch(vector<int> arr, int key){
    int s = 0;
    int e = arr.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
    }

    return -1;
}

int main(){

    vector<int> arr;
    int n;
    int key;
    cout << "How many elements do you want in array: ";
    cin >> n;
    cout << endl;
    for(int i=0;i<n;i++){
        cout << "Enter element: ";
        int temp;
        cin >> temp;
        arr.push_back(temp);
        cout << endl;
    }
    cout << "Which element do you want to find: ";
    cin >> key;
    cout << endl;
    int index = binarysearch(arr, key);
    cout << "Element found at index " << index << endl;
}