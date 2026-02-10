#include <iostream>
using namespace std;

int main(){
    int i = 0;
    // int i = 0;
    for(i; i < 5; i++){
        cout << i << endl;
    }
    cout << i;

    // declaring int i ek baar and then loop ke andar phir se initialise kiye toh koi error nhi aayega kyuki loop ke bahar waala i global variable h aur loop ke andar waala local variable h
    // agar 2 baar global variable declare kiye toh redeclaration error aayega
    // also if you declare a local variable its value will be the same outside of the loop jaise ki agar i bahar globally initialise kiya aur loop ke syntax mein increment kiya toh i ki value same rhegi loop ke bahar


    // nested for loop 
    for(int i = 0; i < 5; i++){
        for(int j=0;j<5;j++){
            cout << i << "-" << j << endl;
        }
    }

    // pattern for filled square
    for(int i=0;i<4;i++){
        for(int j = 0; j<4;j++){
            cout << "*";
        }
        cout << "\n";
    }
    //  hollow square
    for(int i=0; i<5; i++){
        for(int j = 0;j < 5; j++){
            if(i == 0 || i == 4){
                cout << "*";
            }
            else{
                if(j == 0 || j== 4){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }


    // while loop
    while(i < 10){
        cout << "1";
        i++;
    }

    // do while loop
    int dw = 0;
    do{
        cout << dw << endl;
        dw++;
    }
    while(dw < 10);


    // example
    int pin = 123456;
    int enteredCode;

    while(enteredCode != pin){
        cout << "Enter Pin: ";
        cin >> enteredCode;
    }
}