#include <iostream>
using namespace std;

int main() {
    //Declaring variables
    float age = 16.5;
    float gradAge = 18.5; 
    int timeUntilGrad = gradAge - age; //calculating how many years until I graduate.
    // Doing feet and inches seperately and combining them
    float heightFeet = 5;
    float heightInches = 11;
    char grade = 'A';
    string fullName = "Ian McDowell";
    //Calculating height from feet and inches
    float heightTotal = heightFeet + heightInches/12;

    //Printing the variables
    cout << "My name is " << full_name << endl;
    cout << "I have taken a class in C++ and HTML before but I have forgotten a lot" << endl;
    cout << "I am " << age << " years old" << endl;
    cout << "I am " << heightFeet << "'"<< heightInches << endl; 
    cout << "That is " << heightTotal << " feet" << endl;
    cout << "I want to graduate with my degree when I am " << grad_age << " years old" << endl;
    cout << "That is "<< timeUntilGrad << " years from now" << endl;
    cout << "I want an " << grade << " in this class" << endl;
    return 0;
}
