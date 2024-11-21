#include <iostream>
#include <string>

//Namespace definition to avoid repeating "std::" in the future lines
namespace theater_booking{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
}

//Enumeration types used within the main function
enum MovieGenre { ACTION, COMEDY, DRAMA, SCI_FI, HORROR };
enum TicketType { REGULAR, VIP, STUDENT };
enum { A, B, C, D, E };

//Defines alias for String
typedef std::string String;

// Function obtains movie genre
String getGenreName(MovieGenre genre){
    switch (genre){
        case ACTION: return "Action";
        case COMEDY: return "Comedy";
        case DRAMA: return "Drama";
        case SCI_FI: return "Sci-Fi";
        case HORROR: return "Horror";
        default: return "Unknown";
    }
}

// Function calculates ticket price
double calculateTicketPrice(TicketType ticketType){
    switch (ticketType){
        case REGULAR: return 10.00;
        case VIP: return 20.00;
        case STUDENT: return 8.00;
        default: return 0.00;
    }
}

int main(){

    //Declares namespace 
    using namespace theater_booking;

    //Defines variables for username and password
    String userName, password;

    //Obtains user's credentials
    cout << "Enter your username: ";
    cin >> userName;
    cout << "Enter your password: ";
    cin >> password;

    //Executes ticket booking program if the username and password are entered correctly
    if (userName == "Marshall" && password == "Aleksich"){
        cout << "Login successful!" << endl;
    } 
    else{
        cout << "ERROR: Please enter valid username and password." << endl;
        return 0;
    }

    /*Keeps the program running as long as bool is true 
      Will end the ticket booking program if bool is false */
    bool bookAnotherTicket = true;

    //Executes while bool is true
    while (bookAnotherTicket){
        
        //Prompt user for movie genre
        cout << "\nSelect a movie genre:" << endl;
        cout << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n";
        int genreChoice;
        cout << "Enter your choice (1-5): ";
        cin >> genreChoice;
        MovieGenre selectedGenre = static_cast<MovieGenre>(genreChoice - 1);

        //Prompt user for ticket type
        cout << "\nSelect a ticket type:" << endl;
        cout << "1. Regular ($10.00)\n2. VIP ($20.00)\n3. Student ($8.00)\n";
        int ticketChoice;
        cout << "Enter your choice (1-3): ";
        cin >> ticketChoice;
        TicketType selectedTicketType = static_cast<TicketType>(ticketChoice - 1);

        //Calculate ticket price
        double ticketPrice = calculateTicketPrice(selectedTicketType);

        //Display ticket information: genre, type, and price
        cout << "\nYou selected:\n";
        cout << "Movie Genre: " << getGenreName(selectedGenre) << endl;
        cout << "Ticket Type: " << (ticketChoice == 1 ? "Regular" : ticketChoice == 2 ? "VIP" : "Student") << endl;
        cout << "Ticket Price: $" << ticketPrice << endl;

        //Prompts user if they would like to book another ticket
        char choice;
        cout << "\nWould you like to book another ticket? [Y/N]: ";
        cin >> choice;
        bookAnotherTicket = (choice == 'Y' || choice == 'y');
    }

    cout << "Thank you for using the ticket booking system. Goodbye!" << endl;
    return 0;
}