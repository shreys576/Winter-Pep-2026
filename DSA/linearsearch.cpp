#include<iostream>
#include <vector>
using namespace std;

int linearsearch(vector<int> arr, int key){
    for(int i: arr){
        if(i == key && key > 5){
            return key*2;
        }
        else if(i == key && key <= 5){
            return key/2;
        }
    }
    return -1;
}


int main(){

    int n;
    int key;
    vector<int> arr;
    cout << "How many elements do you want in your array: ";
    cin >> n;
    cout << endl;
    for(int i = 0; i<n; i++){
        cout << "Enter element: ";
        int temp;
        cin >> temp;
        arr.push_back(temp);
        cout << endl;
    }
    cout << endl;
    cout << "Enter Key: ";
    cin >> key;
    cout << endl;
    cout << linearsearch(arr, key);

}