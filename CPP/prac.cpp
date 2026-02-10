#include <iostream>
using namespace std;

int main(){
    int a = 6;
    int *p = &a;
    (*p)++;
    cout << a << endl;
}