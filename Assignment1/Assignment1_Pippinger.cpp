#include <iostream> // Lets the user use the input/output objects cin and cout as well as the standard library.
#include<string>
using namespace std; // Lets the user bypass using std:: to access objects, but may cause naming issues later on.

int main()
{
    
    //Declaring variables/Variable Initialization in same line. 

    string name = "Javaar";
    double half_trueage = 17.1;
    char grade = 65 ; // implicit typecasting, converting integer 65 on ASCII Table to an A using char.
    float height = 6.1; 


    int int_age = half_trueage; // implicit type casting, double-half_trueage coverted to int in new variable
    int_age *= 2; // multiplication assignment Operator, shortcut for int_age = int_age * 2

    cout << "My Name is: " << name << endl;
    cout << "This is my first basic program in C++" << endl;
    cout << "age: " << int_age << endl;
    cout << "My height is: " << height << " feet" << endl;
    cout << "I want grade in CISC115: '" << grade << "'" << endl;
    cout << "New Age(float)-year/months:" << half_trueage * 2 << endl;
    cout << "Rounded Height(int):" << int(height) << endl; // explicit typecasting with int 
    ;

    system("pause>0");
    
    return 0;

}
