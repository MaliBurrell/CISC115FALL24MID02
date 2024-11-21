#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>

namespace theater_booking {    // 3. Namespace for all std(cout,cin etc) in main created here

	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
	using std::setprecision;

}

std::string getGenreName(int moviegenre);
double calculateTicketPrice(int ticketype); // function prototypes declared here
std::string movietype(int ticketype);
void inputTest(bool& testVariable);

int main(){

	using namespace theater_booking; // using namespace for main function

	enum MovieGenre {
		ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR // 1. enum types defined here both Moviegenre and Ticketype
	};
	enum TicketType {
		REGULAR = 1, VIP, STUDENT
	};
	enum {
		A, B, C, D, E
	}SeatRow;                  // 2. Anonymous Data Type Seatrow declared here

	typedef std::string string; // 2. typedef used on std::string to string

	int firstUserinput;
	int secondUserinput; // user input that will be converted into enum userGenre and userTicket

	bool machinedriver = true; // sentinel for while loop
	char keepgoing; // char for program loop

	string storedName = "Javaar";  // 6. My name stored as a check for username input 
	string storedPassword = "Pippinger"; // 6. last name stored for password
	string userName;
	string password;      // 6. Prompt user to store their data in these variables.


	cout << "Enter username: "; // input to  check for usernam and password
	getline(cin, userName);

	cout << "Enter password: ";
	getline(cin, password);

	if (userName == storedName and password == storedPassword) { // 6. Use relational operators to check if user input matches
		cout << "Login successful!" << endl << endl;

		while (machinedriver) {

			bool testVariable = false;

			cout << "Select Movie Genre:" << endl;  // 5. Prompt for user, displaying movie options
			cout << "1. Action" << endl;
			cout << "2. Comedy" << endl;
			cout << "3. Drama" << endl;
			cout << "4. Sci-fi" << endl;
			cout << "5. Horror" << endl;
			cout << "Enter Choice ( 1-5 ): ";

			cin >> firstUserinput;
			inputTest(testVariable);
			if (testVariable == true) // test variable to check for cin fail state
				continue;
			else
				cin.ignore(1000, '\n');
			
			if (firstUserinput < 1 or firstUserinput > 5) { // if statement to check user input range
				cout << "Incorrect Input, TRY AGAIN" << endl;
				continue;
			}

			cout << endl << "Select Ticket Type:" << endl; // 5. Prompt for user, displaying ticket types
			cout << "1. Regular" << endl;
			cout << "2. VIP" << endl;
			cout << "3. Student" << endl;
			cout << "Enter Choice ( 1-3 ): ";

			cin >> secondUserinput;
			inputTest(testVariable);
			if (testVariable == true)
				continue;
			else
				cin.ignore(1000, '\n');
			if (secondUserinput < 1 or secondUserinput > 3) {
				cout << "Incorrect Input, TRY AGAIN" << endl;
				continue;
			}

			MovieGenre userGenre = static_cast<MovieGenre>(firstUserinput); // assign user input into enum via static_cast
			TicketType userTicket = static_cast<TicketType>(secondUserinput);
			
			cout << endl << "You selected: " << getGenreName(userGenre) << endl; // 5. Display the return value of functions telling user what they choose
			cout << "Ticket Type: " << movietype(userTicket) << endl;
			cout << fixed << setprecision(2) << "Ticket Price: $" << calculateTicketPrice(userTicket) << endl;

			cout << endl << "Would you like to book another ticker? (Y/N): "; // 7. Ask user if they would like to keep going
			cin.get(keepgoing);
			inputTest(testVariable);
			if (testVariable == true)
				continue;
			else if (keepgoing == 'N' or keepgoing == 'n') {
				machinedriver = false;
				cout << "Thank you for using the theater booking system!";
				continue;
			}
			else if(keepgoing != 'Y' or keepgoing != 'y') {
				cout << "Invalid input, please try again" << endl;
				cin.ignore(1000, '\n');
				continue;
			}
			else
				cin.ignore(1000, '\n');
		}
	}
	else
		cout << "Invalid username or password. Exiting program";
}

std::string getGenreName(int moviegenre) { // 4. Function getGenreName takes moviegenre enum type as input and returns string

	switch (moviegenre) {
	case 1:
		return "Action";
		break;
	case 2:
		return "Comedy";
		break;
	case 3:
		return "Drama";
		break;
	case 4:
		return "Sci_fi";
		break;
	case 5:
		return "Horror";
		break;
	default:
		std::cout << "Incorrect input";
		break;
	}

}

double calculateTicketPrice(int ticketype) { // 4. Fucntion calculateTicketPrice takes ticketype enum as input and returns double

	switch (ticketype) {
	case 1:
		return 10.00;
		break;
	case 2:
		return 20.00;
		break;
	case 3:
		return 8.00;
		break;
	}
}

std::string movietype(int ticketype) {

	switch (ticketype) {
	case 1:
		return "Regular";
		break;
	case 2:
		return "VIP";
		break;
	case 3:
		return "Student";
		break;
	}
}

void inputTest(bool& testVariable) {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Error" << std::endl;
		testVariable = true;
	}
	else
		testVariable = false;
}
