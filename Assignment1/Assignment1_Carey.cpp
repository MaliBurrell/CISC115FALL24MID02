#include<iostream>
#include<string>

using namespace std;
// beginning of Assignment 1 program
int main(){
  // Variable declaration 
    int age; // current age
    float futureAge; // future age
    float height; // current height
    char grade; // expected grade at end
    string fullName; // first name last name

    // variable assignment
    age = 17; 
    futureAge = 10;
    height = 5.9;
    grade = 'A';
    fullName = "Maxwell Carey";
    
    float impl_age = age;
    int expl_height = static_cast<int>(height);

    // output 
    cout << "Hello, my name is: " << fullName << endl;
    cout << "This is my first basic program in C++" << endl;
    cout << "I am currently: " << age << endl;
    cout << "My implicit age is: " << impl_age << endl;
    cout << "Implicit conversion. In ten years, I will be: " << age + futureAge << endl; // implicit conversion
    cout << "My height is: " << height << endl;
    cout << "My explicit height is: " << expl_height << endl;
    cout << "In CISC115, I want an: " << grade << endl; 

    return 0;
}