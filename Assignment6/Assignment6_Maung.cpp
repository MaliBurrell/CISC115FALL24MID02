#include <iostream>
#include <string>

namespace theater_booking
{
    using std::cin;
    using std::cout;
    using std::endl;

    // Define Enumeration Types
    enum MovieGenre
{
    ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR };
    enum TicketType
     { REGULAR = 1, VIP, STUDENT };

    // Typedef for string alias
    typedef std::string String;

    // Anonymous enum for SeatRow
    enum { A = 1, B, C, D, E };

    // Function to get the genre name as a string
    String getGenreName(MovieGenre genre)
{
        switch (genre)
    {
            case ACTION: return "Action";
            case COMEDY: return "Comedy";
            case DRAMA: return "Drama";
            case SCI_FI: return "Sci-Fi";
            case HORROR: return "Horror";
            default: return "Unknown";
        }
    }

    // Function to calculate ticket price
    double calculateTicketPrice(TicketType ticketType)
{
        switch (ticketType)
    {
            case REGULAR: return 10.00;
            case VIP: return 20.00;
            case STUDENT: return 8.00;
            default: return 0.00;
        }
    }
}

int main()
{
    using namespace theater_booking;

    // Step 6: Define username and password
    String userName, password;

    // Prompt user for credentials
    cout << "Enter your username: ";
    cin >> userName;
    cout << "Enter your password: ";
    cin >> password;

    // Validate credentials
    if (userName == "Minkhant" && password == "Maung")
{
        cout << "Login successful!\n";
    }
    else {
        cout << "Login failed. Exiting program.\n";
        return 1;
    }

    // Ticket booking loop
    char continueBooking = 'y';

    while (continueBooking == 'y' || continueBooking == 'Y')
{
        // Step 1: Declare variables for MovieGenre and TicketType
        MovieGenre selectedGenre;
        TicketType selectedTicket;

        // Step 5: Prompt user for MovieGenre
        cout << "\nSelect a Movie Genre:\n";
        cout << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n";
        cout << "Enter your choice (1-5): ";
        int genreChoice;
        cin >> genreChoice;
        selectedGenre = static_cast<MovieGenre>(genreChoice);

        // Step 5: Prompt user for TicketType
        cout << "\nSelect a Ticket Type:\n";
        cout << "1. Regular ($10.00)\n2. VIP ($20.00)\n3. Student ($8.00)\n";
        cout << "Enter your choice (1-3): ";
        int ticketChoice;
        cin >> ticketChoice;
        selectedTicket = static_cast<TicketType>(ticketChoice);

        // Step 4: Output selected options and calculated price
        cout << "\nBooking Summary:\n";
        cout << "Movie Genre: " << getGenreName(selectedGenre) << endl;
        cout << "Ticket Type: ";
        if (selectedTicket == REGULAR)
{
            cout << "Regular";
    }
        else if (selectedTicket == VIP)
{
            cout << "VIP";
    }
        else if (selectedTicket == STUDENT)
{
            cout << "Student";
    }
        cout << endl;
        cout << "Total Price: $" << calculateTicketPrice(selectedTicket) << "\n";

        // Step 7: Prompt for another booking
        cout << "\nWould you like to book another ticket? (y/n): ";
        cin >> continueBooking;
    }

    cout << "\nThank you for using the Movie Ticket Booking System. Goodbye!\n";
    return 0;
}
