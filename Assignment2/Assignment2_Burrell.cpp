#include <iostream>
#include <iomanip>  
#include <string>    
using namespace std;

int main(){
    //Declaring Variables
    string Title;
    string Author;
    double Price;
    double inputPrice;

    //First input data
    cout << "Enter the Book's Title: ";
    getline(cin, Title);
    cout << "Enter the Book's Author: ";
    getline(cin, Author);

    //Input data for the book price 
    cout << "Enter the Book's Price: ";
    while (true) {
        cin >> Price;

        //Checking for proper data type
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(100, '\n'); 
            cout << "Invalid Input; Please enter a valid number: ";
        } 
        else {
            cin.ignore(100, '\n'); 
            break;
        }
    }

    cout << "\n------- Book Details -------" << endl;
    cout << setw(18) << left << "Title: " << Title << endl;
    cout << setw(19) << left << "Author: " << Author << endl;
    cout << setw(20) << left << "Price: " << fixed << setprecision(2) << "$" << Price << endl;

    return 0;

}