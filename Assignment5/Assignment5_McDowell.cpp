#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//function prototypes
//overloaded functions
double calculateArea(double radius);
double calculateArea(double length, double width);
double calculateArea(double base, double height, bool isTriangle);
//temperature functions
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
//void functions
void calculateRectangle(double length, double width, double &area, double &perimeter);
void incrementCounter();
void greetUser(string name, string title = "Mr./Mrs.");

int main()
{
    //int for selecting options
	int operationSelection;
	//bool to check if a selection is valid
	bool selectionSuccess;
	do{
	    //give options
	cout << "Please choose an operation:" << endl;
	cout << "1. Basic calculator\n";
	cout << "2. Temperature conversion\n";
	cout << "3. Rectangle area and perimeter\n";
	cout << "4. Counter function\n";
	cout << "5. Shape area calculation\n";
	cout << "6. Greet user\n";
	cout << "7. Exit\n";
	    //recieve input
	cin >> operationSelection;
	   //choose correct operation based on input
	switch(operationSelection) {
	    //basic calculator selection
	case 1:
		cout << "Basic calculator:\n" << "1. Absolute value\n" << "2. Power\n" << "3. Square root\n";
		//recieve selection
		cin >> operationSelection;
		//choose correct function based on selection
		switch(operationSelection) {
		    //abs function
		case 1:
			double a;
			cout << "What number would you life to take the absolute value of?\n";
			cin >> a;
			cout << "The absolute value of " << a << " is " <<abs(a) << endl;
			selectionSuccess = true;
			break;
			//pow function
		case 2:
			double base, exponent;
			cout << "What base would you like to take the power of?\n";
			cin >> base;
			cout << "What exponent would you like?\n";
			cin >> exponent;
			cout << base << " to the power of " << exponent << " is " << pow(base, exponent) << endl;
			selectionSuccess = true;
			break;
		case 3:
		    //sqrt function
			double s;
			cout << "What number would you like to take the square root of?" << endl;
			cin >> s;
			cout << "The square root of " << s << " is " << sqrt(s) << endl;
			selectionSuccess = true;
			break;
		default:
		//if none of the options are selected give an error
			selectionSuccess = false;
			break;
		}
		break;
	//temperature conversion operation
	case 2:
		double temperature;
		//choose conversion type
		cout << "1. Fahrenheit to celsius\n" << "2. Celsius to fahrenheit\n";
		cin >> operationSelection;
		//reviece temperature input
		cout << "Please input the temperature\n";
		cin >> temperature;
		//choose the correct function for the selection
		if(operationSelection == 1) {
			cout << temperature << "F is " << fahrenheitToCelsius(temperature) << "C";
			selectionSuccess = true;
		} else if (operationSelection == 2) {
			cout << temperature << "C is " << celsiusToFahrenheit(temperature) << "F";
			selectionSuccess = true;
		} else {
		    //if neither is selected give an error
		    selectionSuccess = false;
		}
		break;
	//rectangle  area and perimeter
	case 3:
	    //declare necessary variables
		double width, length, area, perimeter;
		//get dimensions of rectangle
		cout << "Please input the width\n";
		cin >> width;
		cout << "Please input the length\n";
		cin >> length;
		//reciev correct area and perimeter with the function
		calculateRectangle(length, width, area, perimeter);
		//give the correct output
		cout << "The area is " << area << endl;
		cout << "The perimeter is " << perimeter << endl;
		selectionSuccess = true;
		break;
	//counter function
	case 4:
	    //recieve the limit for number of times to call the function
		int increments;
		cout << "How many increments would you like?\n";
		cin >> increments;
		//call function number of times inputted
		for(int i = 1; i<= increments; i++) {
			incrementCounter();
		}
		selectionSuccess = true;
		break;
	case 5:
	    //declare variables used for dimensions
		double z, x;
		cout << "What shape would you like to calculate the area of?"<< endl;
		cout << "1. Circle\n2. Rectangle\n3. Triangle\n";
		//choose the shape
		cin >> operationSelection;
		switch(operationSelection) {
		case 1:
		    //calciulate the circle
			cout << "What is the radius?\n";
			cin >> z;
			cout << calculateArea(z);
			selectionSuccess = true;
			break;
		case 2:
		    //calculate the rectangle
			cout << "What is the length?\n";
			cin >> z;
			cout << "What is the width?\n";
			cin >> x;
			cout << calculateArea(z, x);
			selectionSuccess = true;
			break;
		case 3:
		    //calculate the trangle
			cout << "What is the base?\n";
			cin >> z;
			cout << "What is the height?\n";
			cin >> x;
			cout << calculateArea(z, x, true);
			selectionSuccess = true;
			break;
		default:
		    //if none of the shapes are selected return an error
		    selectionSuccess = false;
			break;
		}
		break;
	case 6: {
	    //variables for storing outputs and selections
		string nameInput, titleInput;
		char titleCheck;
		cout << "What is your name?\n";
		cin >> nameInput;
		cout << "What is your title?\n";
		cin >> titleInput;
		cout << "Would you like to print your title? (Y/N) \n";
		cin >> titleCheck;
		if(titleCheck == 'Y') {
		    //if the user wants their title printed include the title
			greetUser(nameInput, titleInput);
			selectionSuccess = true;
		} else if (titleCheck == 'N') {
		    //if the user does not want their title printed do not include
			greetUser(nameInput);
			selectionSuccess = true;
		} else {
		    //If neither Y nor N is selected as the option give an error
		    selectionSuccess = false;
		}
	}
	break;
	case 7:
	    //exit
		cout << "Exiting program\n";
		selectionSuccess = true;
		break;
	default:

		break;
	}
	//If there is an error with a selection, tell the user
	if(selectionSuccess == false){
	    cout << "Input error: Please try again\n";
	}
	//if there is an error with data input types clear the istream
	if(cin.fail() == true){
	    cin.clear();
	    cin.ignore(1000, '\n');
	}
} while (selectionSuccess == false); //repeat the process until a correct selection is carried out
	return 0;
}
//calcualte and return the area of a circle
double calculateArea(double radius) {
	return 3.14*radius*radius;
}
//calculte and return the area of a rectangle
double calculateArea(double length, double width) {
	return length*width;
}
//calculate and return the area of a triangle
double calculateArea(double base, double height, bool isTriangle) {
	return base*height/2;
}

//convert F to C and return
double fahrenheitToCelsius(double fahrenheit) {
	return (fahrenheit-32)*5/9;
}
//convert C to F and return
double celsiusToFahrenheit(double celsius) {
	return celsius*9/5+32;
}
//Calcualte  area and perimeter of a rectangle and pass the references
void calculateRectangle(double length, double width, double &area, double &perimeter) {
	area=length*width;
	perimeter = 2*length+2*width;
}
//increase static counter by 1 and output 
void incrementCounter() {
	static int counter = 1;
	cout << counter++ << endl;
}
//output name and title 
void greetUser(string name, string title) {
	cout << "Hello " << title << " " << name << endl;
}