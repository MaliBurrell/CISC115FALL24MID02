#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// prototypes for user defined functions
void sortNames(string* names, int size);
bool searchName(string* names, int size, string& target);
string findLongestName(string* names, int size);
int countVowels(string* names, int size);

int main()
{
    bool loop = true;
    char reset;
    
    // while loop to help with input verification without ending program
    while (loop)
    {
        int size;
        cout << "Enter the number of names: "; // prompt for number/int of names in array
        cin >> size; // input for array size
        if (cin.fail() || size == 0 || size < 0) // input verification for non ints/0/and negatives
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "You entered an invalid input, TRY AGAIN!" << endl; // output for bad input
            continue;
        }
        else
            cin.ignore(1000, '\n');
        
        //
        string* array = new string[size]; // declared pointer-array that points to string array in heap using new
        
        //
        cout << "Enter " << size << " names. " << endl; // text telling user how many names they can enter

        for (int i = 0; i < size; i++)
        {
            cout << "Enter name " << i + 1 << ": "; // prompt for names in array and number position
            getline(cin, array[i]); // getline for cin input and array index
        }
        
        //
        sortNames(array, size); // void function to sort names and display to screen 
        
        //
        string target;
        bool targetresult;
        
        //
        cout << endl << "Enter a name to search: "; // prompt for name to search in array
        getline(cin, target); 
        targetresult = searchName(array, size, target); // bool function returns true or false if name is in list
        if (targetresult == true) // if statement to display result of search
            cout << "'" << target << "'" << " found in the list." << endl;
        else
            cout << "'" << target << "'" << " not found in the list." << endl;
        
        //
        cout << endl << "Longest Name: " << findLongestName(array, size) << endl; // string function to find longest name
        
        //
        cout << "Total vowel count: " << countVowels(array, size) << endl << endl; // int function to count all vowels in array
        
        //
        delete[] array; // delete with brackets to delete array
        array = nullptr; // set pointer to null
        
        //
        cout << "Do you want to reset? 'y' or anything else to quit: "; // ask user if they want to reset or exit
        cin.get(reset);
        cin.ignore(1000, '\n');
        reset = tolower(reset);
        if (reset == 'y')
            continue;
        else
        {
            cout << "GOODBYE.";
            loop = false;
        }
    }
    return 0;
}

void sortNames(string* arrayNames, int sizeofArray) // header for sort name function
{ // definition
    cout << endl << "sorted List of Names.." << endl; // text
    string firstName; // 4 variables used in function
    string secondName;
    int comparison;
    int counter1 = 0;

    for (counter1 ; counter1 < sizeofArray ; ) // for loop that starts at index 0 and iterates until -1 than array size
    {
        firstName = arrayNames[counter1]; // first name that will be anchor point for comparsions
        
        for (int counter2 = counter1 + 1 ; counter2 <= sizeofArray ; counter2++) // loop for second name that first name compares to
        {
            if (counter2 == sizeofArray) // special if statement -- if first name can iterate across entire array without triggering a switch index counter1 moves up ++1
            {
                counter1++;
                break;
            }

            secondName = arrayNames[counter2]; // assigning second name to variable
            comparison = firstName.compare(secondName); // compare first name to second name
            
            if (comparison == 0 || comparison < 0) // if first name is equal or less than second name no switch occurs and second loop-counter2 moves on ++1
                continue;
            
            else
            {
                arrayNames[counter1] = secondName; // if first name is greater than second name they must switch positions second takes first place in index
                arrayNames[counter2] = firstName; // first now takes seconds place in index and a break occurs reseting the entire second loop to beginning
                break; // second name now first will be compared to all indexes if second loop-counter2 makes it to the last index master loop-counter1 will move a position ++1
            }
        }
    }
    for (int counter3 = 0; counter3 < sizeofArray; counter3++) // once array has been sorted output the array with basic for loop
        cout << counter3 + 1 << ": " << arrayNames[counter3] << endl;
}
//

bool searchName(string* arrayNames, int sizeofArray, string& targetName) // function to search for name in array
{
    string comparisonName;
    
    for (int counter = 0 ; counter < sizeofArray ; counter++) // for loop iterates across array looking for name
    {
        comparisonName = arrayNames[counter]; // assign array name to variable
        if (targetName == comparisonName) // see if target name matches array name
            return true;
    }
    return false;
}
//

string findLongestName(string* arrayNames, int sizeofArray) // function longest name
{
    int lengthsize = 0;
    int indexLongestName = 0;

    for (int counter = 0 ; counter < sizeofArray ; counter++) // for loop iterates across array
    {
        if (arrayNames[counter].length() > lengthsize) // length size was initialized to zero and array name is compared to see if greater than, all following names will compare 
        {
            lengthsize = arrayNames[counter].length(); // assign current name length size if greater than current lenghtsize to lenghtsize
            indexLongestName = counter; // variable to keep track of longest name in array when if is true
        }
    }
    return arrayNames[indexLongestName]; // return of longest name
}
//

int countVowels(string* arrayNames, int sizeofArray) // function vowel counter
{
    int vowelTally = 0; // vowel counter variable
    
for (int counter1 = 0 ; counter1 < sizeofArray ; counter1++) // loop to iterate across array
    {
        string name = arrayNames[counter1]; // assign current name to variable to be looked at
        
        for (int counter2 = 0 ; counter2 < name.length() ; counter2++) // second loop to iterate across name looking for vowels using name length as condition
        {
            char letter = tolower(name[counter2]); // assign letter in name/lower case to variable
            
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') // if letter equals any vowel tally vowelTally ++1
                vowelTally++;
        }
    }
    return vowelTally; // return for vowel tally
}
