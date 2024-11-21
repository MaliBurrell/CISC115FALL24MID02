#include <iostream>
#include <iomanip>

// putting standard functions in name space for booking theater tickets
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

// Using the new namespace we created
using namespace theater_booking;

// Defining enumerations using movie genres and the different ticket types
enum movieGenre {ACTION, COMEDY, DRAMA, SCI_FI, HORROR};
enum ticketType {REGULAR, VIP, STUDENT};

// declaring string using typedef instead of #include
typedef std::string String;

// anonymous enumeration for rows of seats
enum {A, B, C, D, E} seatRow;

// function to take enumeration value and return genre to a string
String getGenreName(movieGenre film) {
	// String to return what type of movie it is
	String MovieType;
	// switch case to assign enumeration values to a string
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

// Calculating price of ticket based off of enumeration value
double calculateTicketPrice (ticketType ticket) {
	// string to return what the price of the ticket is
	double ticketPrice;
	//switch case to assign enumeration values to a string
	switch (ticket) {
		case 0:
		ticketPrice = 10.00;
		break;
	case 1:
		ticketPrice = 20.00;
		break;
	case 2:
		ticketPrice = 8.00;
		break;
	}
	return ticketPrice;
}

int main () {

	// Variable Declaration
	String username, password;
	movieGenre mGenre;
	ticketType tType;
	int genreSelection, ticketSelection;

	// do while loop for username, password, and genre and ticket selection
	do {
		cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

		// if statement for username and password
		if (username != "Maxwell" || password != "Carey") {
            cout << "Invalid username or password. Please try again." << endl;
            continue;
		}
		cout << "Successfully logged into your account. Welcome!\n" << endl;

		// Asks user what movie genre they want
		cout << "Select what movie genre you would like to see:\n"
             << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n"
             << "Enter choice (1-5): ";
        cin >> genreSelection;
        mGenre = static_cast<movieGenre>(genreSelection - 1);

		// Asks user what type of ticket they want
		cout << "Select what type of ticket you want to book:\n"
             << "1. Regular ($10)\n2. VIP ($20)\n3. Student ($8)\n"
             << "Enter choice (1-3): ";
        cin >> ticketSelection;
        tType = static_cast<ticketType>(ticketSelection - 1);

		// Outputs of user selected options
		cout << "\nTicket Details:\n";
        cout << "Movie Genre: " << getGenreName(mGenre) << endl;
        cout << "Ticket Type: ";
        if (tType == REGULAR) cout << "Regular";
        else if (tType == VIP) cout << "VIP";
        else cout << "Student";
        cout << endl;
        cout << "Total Price: $" << calculateTicketPrice(tType) << "\n" << endl;

		// Option for user to book another ticket
		char option;
        cout << "Would you like to book another ticket? (y/n): ";
        cin >> option;
        if (option != 'y' && option != 'Y') break;

    } while (true);

    cout << "Thanks for using our Theater Booking System to book your movie tickets. We hope you have a good watching experience!" << endl;
    return 0;
	} 