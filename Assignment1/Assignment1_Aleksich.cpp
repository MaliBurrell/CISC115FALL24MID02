#include <iostream>
using namespace std;
int main()
{
    double age = 18.31532252; 
    int realAge = (int)age;
    /* Data type for my age;
       I used explicit type conversion for this data type */

    float heightOne = 3.8; 
    float subtractHeight = 0.9;
    double heightTwo = heightOne + 3;
    double finalHeight = heightTwo - subtractHeight;
    //These are all the data types for my height; I used multiple to demonstrate implicit type conversion.

    int roundedHeight = (int)finalHeight;
    //This is another example of explicit type conversion

    char grade = 'A';
    //Data type for my grade

    string fullName = "Marshall Aleksich";
    //Data type for my name

    cout<< "My name is " <<fullName<< "." <<endl;
    cout<< "I have never used C++, but I have used Java before." <<endl;
    cout<< "I am " <<realAge<< " years old and currently a freshman." <<endl;
    cout<< "My height is " << finalHeight << "." <<endl;
    cout<< "At the end of the semester, I hope to obtain an " << grade << " in this class." <<endl;
    cout<< "Rounded height: " <<roundedHeight<< "." <<endl;
    cout<< "Age before conversion: " << age << "." <<endl;
}