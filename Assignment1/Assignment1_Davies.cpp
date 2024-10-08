#include <iostream>
#include <string>

using namespace std;

int main() {
    // declare variables
    int age;
    float height;
    char grade;
    string full_name;
    
    // assign values
    age = 20;
    height = 6.2;
    grade = 'A';
    full_name = "Ehren Davies";
    
    age += 10;
    
    float impl_age = age;
    int expl_height = static_cast<int>(height);

    cout << "My name is: " << full_name << endl;
    cout << "This is my first basic program in C++" << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Grade I want in CISC115: " << grade << endl;
    cout << "New Age (float): " << impl_age << endl;
    cout << "Rounded Height (int): " << expl_height << endl;
    
    return 0;
}