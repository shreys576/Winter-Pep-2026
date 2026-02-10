#include <iostream>
using namespace std;

void hello(){
    cout << "Hello" << endl;
}
void hello2(){
    hello();
}

int add(){
    cout << "Hell Yeah\n";
    return 10;
}

float subtract(float a, float b){
    float diff;
    if(a > b){
        diff = a - b;
    }
    else{
        diff = b - a;
    }
    return diff;
}

int main(){
    cout << subtract(1.4, 2.9) << endl;
}

// c++ mein function declaration ka order matter krta h toh agar hello2 function jo hello function ko call kr rha h usse pehle likha hoga toh error aayega
// agar non void function jaise int add waala function use kiye toh woh ek value return krega jo bhi uss function ka datatype hoga jaise ki upar integer tha toh woh integer value return krega
// agar non void function ko aise hi call krdiya toh bas cout waali statement print hogi

// function declare krte time jo values dete h woh parameters jaise subtract mein float a aur float b parameters aur call krte time jo values pass kre woh arguments jaise main function mein 1.4 aur 2.9 arguments


