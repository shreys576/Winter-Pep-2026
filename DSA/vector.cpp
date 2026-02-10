#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec1 = {2,3,1,5,4};
    vector<char> vec2(5);
    // cout << vec1.at(10);
    cout << vec1[3] << endl;
    vec1.push_back(10);
    for(int i: vec1){
        cout << i << " ";
    }
    cout << endl;
    vec1.pop_back();
    for(int i: vec1){
        cout << i << " ";
    }
    cout << endl;
    cout << vec1.size() << endl;
    vec1.clear();
    for(int i: vec1){
        cout << i << " ";
    }
}