#include <iostream>
using namespace std;

int main() {
    //setup for adding variables
    int age;
    float grad_age; //used to convert int to float later
    float heightfoot;
    float heightinch; //height separated so it can be combined in a better way later
    char grade;
    string full_name;
    //variables
    age = 20;
    grad_age = age + 1; //math operation, int to float
    heightfoot = 5;
    heightinch = 9;
    grade = 'A';
    full_name = "David Janney";
    //printing time!
    cout << "My name is " << full_name << endl;
    cout << "This is my first program in C++" << endl;
    cout << "I am " << age << " years old" << endl;
    cout << "My height is " << heightfoot << " feet and " << heightinch << " inches" << endl;
    cout << "I want to graduate with my degree when I am " << grad_age << " years old" << endl;
    cout << "I want an " << grade << " in this class" << endl;
    return 0;
    /*
    to run, do:
    g++ Assignment1_Janney.cpp
    ./a.out
    */
}
