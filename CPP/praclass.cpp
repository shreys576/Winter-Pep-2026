#include <iostream>
using namespace std;

class Student{
    public:
    string name;
    string std;
    string course;

    Student(string name, string std, string course){
        this->name = name;
        this->std = std;
        this->course = course;
    }
    void printinfo(){
        cout << "Name : " << this->name << "\nClass: " << this->std << "\nCourse: " << this->course << endl;
    }
};

int main(){
    Student *s1 = new Student("ABC","12","BTech");
    s1->printinfo();
}