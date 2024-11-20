#include <iostream>
#include <string>

namespace theater_booking {
    using std::cin;
    using std::cout;
    using std::endl;

    // Define enumeration types
    enum MovieGenre { ACTION, COMEDY, DRAMA, SCI_FI, HORROR };
    enum TicketType { REGULAR, VIP, STUDENT };

    // Typedef for string alias
    typedef std::string String;

    // Anonymous enum for seat rows
    enum { A, B, C, D, E } SeatRow;

    // Function to get genre name as a string
    String getGenreName(MovieGenre genre) {
        switch (genre) {
            case ACTION: return "Action";
            case COMEDY: return "Comedy";
            case DRAMA: return "Drama";
            case SCI_FI: return "Sci-Fi";
            case HORROR: return "Horror";
            default: return "Unknown Genre";
        }
    }

    // Function to calculate ticket price
    double calculateTicketPrice(TicketType ticketType) {
        switch (ticketType) {
            case REGULAR: return 10.00;
            case VIP: return 20.00;
            case STUDENT: return 8.00;
            default: return 0.00;
        }
    }
}

int main() {
    using namespace theater_booking;

    String userName, password;
    MovieGenre genre;
    TicketType ticketType;
    int genreChoice, ticketChoice;

    do {
        // Authentication
        cout << "Enter username: ";
        cin >> userName;
        cout << "Enter password: ";
        cin >> password;

        if (userName != "Ehren" || password != "Davies") {
            cout << "Error: Invalid username or password." << endl;
            continue;
        }
        cout << "Login successful!\n" << endl;

        // Prompt for movie genre
        cout << "Select a movie genre:\n"
             << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n"
             << "Enter choice (1-5): ";
        cin >> genreChoice;
        genre = static_cast<MovieGenre>(genreChoice - 1);

        // Prompt for ticket type
        cout << "Select a ticket type:\n"
             << "1. Regular ($10)\n2. VIP ($20)\n3. Student ($8)\n"
             << "Enter choice (1-3): ";
        cin >> ticketChoice;
        ticketType = static_cast<TicketType>(ticketChoice - 1);

        // Output selected options and price
        cout << "\nTicket Details:\n";
        cout << "Movie Genre: " << getGenreName(genre) << endl;
        cout << "Ticket Type: ";
        if (ticketType == REGULAR) cout << "Regular";
        else if (ticketType == VIP) cout << "VIP";
        else cout << "Student";
        cout << endl;
        cout << "Total Price: $" << calculateTicketPrice(ticketType) << "\n" << endl;

        // Ask if user wants to book another ticket
        char choice;
        cout << "Do you want to book another ticket? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') break;

    } while (true);

    cout << "Thank you for using the Theater Booking System. Goodbye!" << endl;
    return 0;
}