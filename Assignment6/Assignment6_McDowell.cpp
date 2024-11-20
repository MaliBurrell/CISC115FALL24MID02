#include <iostream>
#include <iomanip>

//PLACING STD FUNCTIONS IN THEATER_BOOKING NAMESPACE
namespace theater_booking {
	using std::cin;
	using std::cout;
	using std::string;
	using std::istream;
	using std::fixed;
	using std::showpoint;
	using std::setprecision;
	using std::endl;
}
//REFERENCING THEATER_BOOKING NAMESPACE
using namespace theater_booking;
//DELCARING ENUMS
enum MovieGenre { ACTION, COMEDY, DRAMA, SCI_FI, HORROR };
enum TicketType { REGULAR, VIP, STUDENT };
//DELCARING String AS AN ALAIS FOR string
typedef std::string String;
//DELCARING ANONYMOUS ENUM
enum { A, B, C, D, E } SeatRow;
//FUNCTION TO RETURN GENRE NAME IN STRING BASED ON VALUE OF ENUM
String getGenreName(MovieGenre film) {
	//STRING TO RETURN
	String MovieType;
	//ASSIGN CORRECT VALUE TO STRING
	switch (film) {
	case ACTION:
		MovieType = "Action";
		break;
	case COMEDY:
		MovieType = "Comedy";
		break;
	case DRAMA:
		MovieType = "Drama";
		break;
	case SCI_FI:
		MovieType = "Sci fi";
		break;
	case HORROR:
		MovieType = "Horror";
		break;
	}
	return MovieType;
}
//FUNCTION TO CALCULATE TICKET PRICE BASED ON VALUE OF ENUM
double calculateTicketPrice(TicketType ticket) {
	//VALUE TO RETURN
	double price;
	//CHOOSE CORRECT VALUE BASED ON ENUM
	switch (ticket) {
	case 0:
		price = 10.00;
		break;
	case 1:
		price = 20.00;
		break;
	case 2:
		price = 8.00;
		break;
	}
	return price;
}

int main()
{
	//DECLARE VARIABLES FOR STORING INPUT OF FILM AND TICKET TYPE
	int film, ticket;
	//DELCARE STRINGS FOR STORING USERNAME AND PASSWOR INPUT AND FOR STORING OUTPUT OF TICKET TYPE
	String ticketTypeOutput, userName, password;
	//ENUM VARIABLES FOR STORING FILM AND TICKET IONFORMATION
	MovieGenre filmGenre;
	TicketType ticketPrice;
	//BOOL TO STORE SUCCESS OR FAILURE OF INPUT
	bool failure;
	//CHAR TO INPUT RESPONSE TO WHETHER USER WOULD LIKE TO BOOK ANOTHER TICKET
	char repeatYN;
	do {
		//ASK FOR LOGIN INFORMATION
		cout << "Enter username: ";
		cin >> userName;
		cout << "Enter password: ";
		cin >> password;
		//CHECK IF CORRECT, IF NOT BREAK OUT OF LOOP TO TERMINATE
		if (userName == "Ian" && password == "McDowell") {
			cout << "Succesful username and password entry\n";
		}
		else {
			cout << "Incorrect username and/or password. TERMINATING PROGRAM.";
			break;
		}
		do {
			//RECIEVE AN INPUT FOR FILM TYPE
			cout << "Select a genre:\n" << "1. Action\n" << "2. Comedy\n" << "3. Drama\n" << "4. Sci fi\n" << "5. Horror\n";
			cin >> film;
			//SELECT CORRECT ENUM VALUE BASED ON INPUT
			switch (film) {
			case 1:
				filmGenre = ACTION;
				failure = false;
				SeatRow = A;
				break;
			case 2:
				filmGenre = COMEDY;
				SeatRow = B;
				failure = false;
				break;
			case 3:
				filmGenre = DRAMA;
				SeatRow = C;
				failure = false;
				break;
			case 4:
				filmGenre = SCI_FI;
				SeatRow = D;
				failure = false;
				break;
			case 5:
				filmGenre = HORROR;
				SeatRow = E;
				failure = false;
				break;
			default: //IF AN INCORRECT VALUE IS INPUTTED REPEAT THE LOOP
				cout << "Please select a number from 1-5\n";
				failure = true;
			}
			if (failure == true) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		} while (failure == true);

		do {
			//RECIEVE AN INPUT FOR TICKET TYPE
			cout << "Select a ticket type:\n" << "1. Regular\n2. VIP\n3. Student\n";
			cin >> ticket;
			//SELECT CORRECT ENUM VALUE BASED ON INPUT
			switch (ticket) {
			case 1:
				ticketPrice = REGULAR;
				ticketTypeOutput = "Regular";
				failure = false;
				break;
			case 2:
				ticketPrice = VIP;
				ticketTypeOutput = "VIP";
				failure = false;
				break;
			case 3:
				ticketPrice = STUDENT;
				ticketTypeOutput = "Student";
				failure = false;
				break;
			default: //IF INCORRECT INPUT, REPEAT LOOP
				cout << "Please select a number from 1-3\n";
				failure = true;
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		} while (failure == true);
		//OUTPUT SELECTIONS
		cout << "You chose: " << getGenreName(filmGenre) << endl;
		cout << fixed << showpoint;
		cout << "You chose the ticket type: " << ticketTypeOutput << endl;
		//OUTPUT PRICE
		cout << "Ticket price is: $" << setprecision(2) << calculateTicketPrice(ticketPrice) << endl;
		do {
			//ASK IF USER WOULD LIKE TO REPEAT
			cout << "Would you like to book another ticket? (Y/N)\n";
			cin >> repeatYN;
			//IF NOT BREAK OUT OF LOOP TO TERMINATE
			if (repeatYN == 'N') {
				cout << "THANK YOU, TERMINATING PROGRAM.";
				break;
			}
			else if (repeatYN == 'Y') { // IF YES REPEAT PROGRAM
				failure = false;
				break;
			}
			else { //IF INCORRCT INPUT IS GIVEN, REPEAT LOOP
				failure = true;
				cin.clear();
				cin.ignore(1000, '\n');
			}

		} while (failure == true);

		//REPEAT PROGRAM UNTIL USER SELECT 'N'
	} while (repeatYN == 'Y');
	return 0;
}