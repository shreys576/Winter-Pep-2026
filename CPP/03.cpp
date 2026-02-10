#include <iostream>
using namespace std;

void increment(int x){
    x++;
    cout << "Inside Function passed by value: " << x << endl;
}

void increase(int &x){
    x++;
    cout << "Inside Function passed by reference: " << x << endl;
}

int main(){
    int age = 5;
    int &ref = age;
    ref = 20;
    cout << age << endl;
    increment(age);
    cout << "Inside main Function: " << age << endl;
    increase(age);
    cout << "inside main function: " << age << endl;
}