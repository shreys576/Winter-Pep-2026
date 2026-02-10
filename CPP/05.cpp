#include <iostream>
using namespace std;

class Car{
    public:
    string name;
    int speed;
    string color;
// Constructor Method below
// same name as class name
// no return type
// called automatically when object is created

    // Car(){
    //     cout << "Default constructor method called" << endl;
    // }

    Car(string x){
        name = x;
    }

    Car(int speed){
        this->speed = speed;
    }
    void increasespeed(){

    }

    void fly(){

    }
};

int main(){
    Car c1("Toyota");
    Car c2(24);
    Car *c3 = new Car(56);

    cout << c3 -> speed << endl;
    // cout << c1.speed << endl;
}

// for good practise (achi aadatein) always prefer to use constructor method
// whenever object is created, default constructor will run always (at least)
// if no parameter passed, default constructor will run
// else parameterised constructor
// if parameter name is same as class variable name, use this keyword
// this keyword changes value of the object rather than use default value
// normal cases mein you can't delete objects kyuki woh stack mein hai toh automatically scope ke bahar jaane pe delete ho jaayenge
// if you want to delete use new keyword and create object in heap memory where you can delete it too