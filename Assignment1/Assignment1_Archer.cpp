//Solomon Archer
#include <iostream>
using namespace std;
//Declare variables
int age, age_in_decade;
float age2;
double height, height2;
char grade;
string full_name;
int main (){
//Assign values 
full_name = "Solomon Archer";
age = 22;
height = 5.11;
grade = 'A';
//Print variables
cout << "My name is " << full_name << "." << endl;
cout << "This is my first basic program in C++." << endl;
cout << "Age: " << age << endl;
cout << "Height: " << height << endl;
cout << "I want an " << grade <<" in CISC115" << endl;
//Basic operation
age_in_decade = age + 10;
cout << "My age in 10 years is " << age_in_decade << endl;
//Type conversion (implicit)
float age_tofloat = age;
cout << "Converted age to float: " << age_tofloat << endl; 
//Type conversion (explicit)
double height_toint = static_cast<int>(height);
cout << "Rounded height (int): " << height_toint << endl;    
}   