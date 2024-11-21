//Solomon Archer
#include <iostream>
#include <string>
using namespace std;

// movie genre enum
enum MovieGenre {
    ACTION,
    COMEDY,
    DRAMA,
    SCI_FI,
    HORROR
};

// ticket type enum
enum TicketType {
    REGULAR,
    VIP,
    STUDENT
};

//  typedef alias for string
typedef string String;

// anonymous enum for seatrow
enum { A, B, C, D, E };

// namespace to avoid repeated use of std::
namespace theater_booking {
    using std::cin;
    using std::cout;
    using std::endl;
}

// get genre name 
String getGenreName(MovieGenre genre) {
    switch (genre) {
        case ACTION: return "Action";
        case COMEDY: return "Comedy";
        case DRAMA: return "Drama";
        case SCI_FI: return "Sci-Fi";
        case HORROR: return "Horror";
        default: return "Unknown";
    }
}

// calculate ticket price
double calculateTicketPrice(TicketType ticket) {
    switch (ticket) {
        case REGULAR: return 10.00;
        case VIP: return 20.00;
        case STUDENT: return 8.00;
        default: return 0.0;
    }
}

int main() {
    using namespace theater_booking;

    String userName, password;
    bool booking = true;

    while (booking) {
        // prompt for username and password
        cout << "Enter username: ";
        cin >> userName;
        cout << "Enter password: ";
        cin >> password;

        //  check if  credentials are valid 
        if (userName == "Solomon" && password == "Archer") {
            cout << "Login successful!\n";

            // ask for movie genre 
            cout << "Select a Movie Genre:\n"
                 << "1. Action\n"
                 << "2. Comedy\n"
                 << "3. Drama\n"
                 << "4. Sci-Fi\n"
                 << "5. Horror\n"
                 << "Enter your choice: ";
            int genreChoice;
            cin >> genreChoice;

            MovieGenre genre = static_cast<MovieGenre>(genreChoice - 1);
            String genreName = getGenreName(genre);

            // ask for ticket type
            cout << "Select a Ticket Type:\n"
                 << "1. Regular\n"
                 << "2. VIP\n"
                 << "3. Student\n"
                 << "Enter your choice: ";
            int ticketChoice;
            cin >> ticketChoice;

            TicketType ticket = static_cast<TicketType>(ticketChoice - 1);
            double price = calculateTicketPrice(ticket);

            // display selected choices
            cout << "You selected " << genreName << " movie and a "
                 << (ticket == REGULAR ? "Regular" :
                     ticket == VIP ? "VIP" : "Student") << " ticket.\n";
            cout << "Total Price: $" << price << endl;

            // ask if the user wants to book another ticket

            cout << "Do you want to book another ticket? (1 for Yes, 0 for No): ";
            cin >> booking;
        } else {
            cout << "Error: Invalid username or password. Try again.\n";
        }
    }

    cout << "Thank you for using the theater booking system!\n";
    return 0;
}
