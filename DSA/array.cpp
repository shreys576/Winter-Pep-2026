#include <iostream>
using namespace std;

int main(){
    // finding the largest element in an array
    int arr[] = {1, 8, 7, 56, 90};
    int largest = -1;
    int secondlargest = -1;
    for(int i:arr){
        if(i>largest){
            largest = i;
        }
    }
    for(int i:arr){
        if((i > secondlargest)&& (i!=largest)){
            secondlargest = i;
        }
    }
    cout << secondlargest;

}