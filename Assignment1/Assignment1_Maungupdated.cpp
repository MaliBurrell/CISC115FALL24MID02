#include<iostream>
#include<string>
using namespace std;
int main()
{
//Declaring variables
int age;
double newage;
float height;
double newheight;
char grade;
string name;

//Assign value;
age = 25;
height = 5.11;
grade = 'A';
name = "Min Khant Maung"  ;

newage = age / 5;
newheight = (height + .2);

cout << "My name is "<< name <<endl;
cout <<"This is my first basic program in C++1" <<endl;
cout <<"Age: " << age <<endl;
cout <<"Height: " << height <<endl;
cout <<"I want Grade in CISC115: " << grade << endl;
cout <<"New Age (double): " << newage <<endl;
cout <<"rounded Height (int): " <<newheight <<endl;

return 0;
}