#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int &ref = a;
    int *ptr = &a;

    cout << &ref << endl; 
    // gives address where a is created


    cout << ptr <<endl;
    // pointer only stores address agar *ptr = a krte toh error aata (invalid conversion)


    cout << *ptr << endl;
    // derefrencing means taking the value out of the pointer we use * dobaara

    *ptr=6;
    cout << a << endl;

    ref++;
    cout << a << endl;

    // reference must be initialised cannot be left null
}